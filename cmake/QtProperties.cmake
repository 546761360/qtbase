define_property(TARGET
    PROPERTY
        QT_PLUGINS
    BRIEF_DOCS
        "List of Qt plug-ins associated with a given Qt module."
    FULL_DOCS
        "This is a property on Qt modules.
        For instance, sqlite;odbc for Sql"
)

define_property(TARGET
    PROPERTY
        MODULE_PLUGIN_TYPES
    BRIEF_DOCS
        "List of plugin categories associated to the Qt module"
    FULL_DOCS
        "This is a property on Qt modules.
        For instance, sqldrivers for Sql."
)

define_property(TARGET
    PROPERTY
        QT_PLUGIN_CLASS_NAME
    BRIEF_DOCS
        "Class name of the Qt plug-in"
    FULL_DOCS
        "This is a property on Qt plug-ins.
        For instance, QICOPlugin for the qico plug-in"
)

define_property(TARGET
    PROPERTY
        QT_MODULE
    BRIEF_DOCS
        "Qt module associated with a plug-in."
    FULL_DOCS
        "This is a property on Qt plug-ins.
        For instance, Sql for qsqlite"
)

define_property(TARGET
    PROPERTY
        QT_DEFAULT_PLUGIN
    BRIEF_DOCS
        "Indicates whether a plug-in is added by default."
    FULL_DOCS
        "This is a property on Qt plug-ins.
        It is mainly used to indicate if a plug-in should be added
        to the default set of plug-ins when building a static app -
        for instance, which QPA should be linked."
)

define_property(GLOBAL
    PROPERTY
        QT_KNOWN_PLUGINS
    BRIEF_DOCS
        ""
    FULL_DOCS
        ""
)
