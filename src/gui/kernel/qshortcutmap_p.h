/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtGui module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl-3.0.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or (at your option) the GNU General
** Public license version 3 or any later version approved by the KDE Free
** Qt Foundation. The licenses are as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-2.0.html and
** https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QSHORTCUTMAP_P_H
#define QSHORTCUTMAP_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include <QtGui/private/qtguiglobal_p.h>
#include "QtGui/qkeysequence.h"
#include "QtCore/qvector.h"
#include "QtCore/qscopedpointer.h"

QT_REQUIRE_CONFIG(shortcut);

QT_BEGIN_NAMESPACE

// To enable dump output uncomment below
//#define Dump_QShortcutMap

class QKeyEvent;
struct QShortcutEntry;
class QShortcutMapPrivate;
class QObject;

class Q_GUI_EXPORT QShortcutMap
{
    Q_DECLARE_PRIVATE(QShortcutMap)
public:
    QShortcutMap();
    ~QShortcutMap();

    typedef bool (*ContextMatcher)(QObject *object, Qt::ShortcutContext context);

    int addShortcut(QObject *owner, const QKeySequence &key, Qt::ShortcutContext context, ContextMatcher matcher);
    int removeShortcut(int id, QObject *owner, const QKeySequence &key = QKeySequence());
    int setShortcutEnabled(bool enable, int id, QObject *owner, const QKeySequence &key = QKeySequence());
    int setShortcutAutoRepeat(bool on, int id, QObject *owner, const QKeySequence &key = QKeySequence());

    QKeySequence::SequenceMatch state();

    bool tryShortcut(QKeyEvent *e);
    bool hasShortcutForKeySequence(const QKeySequence &seq) const;

#ifdef Dump_QShortcutMap
    void dumpMap() const;
#endif

private:
    void resetState();
    QKeySequence::SequenceMatch nextState(QKeyEvent *e);
    void dispatchEvent(QKeyEvent *e);

    QKeySequence::SequenceMatch find(QKeyEvent *e, int ignoredModifiers = 0);
    QKeySequence::SequenceMatch matches(const QKeySequence &seq1, const QKeySequence &seq2) const;
    QVector<const QShortcutEntry *> matches() const;
    void createNewSequences(QKeyEvent *e, QVector<QKeySequence> &ksl, int ignoredModifiers);
    void clearSequence(QVector<QKeySequence> &ksl);
    int translateModifiers(Qt::KeyboardModifiers modifiers);

    QScopedPointer<QShortcutMapPrivate> d_ptr;
};

QT_END_NAMESPACE

#endif // QSHORTCUTMAP_P_H
