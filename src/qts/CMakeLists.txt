set(krossqtsplugin_LIB_SRCS plugin.cpp)
ecm_qt_declare_logging_category(
    krossqtsplugin_LIB_SRCS
    HEADER kross_qts_plugin_debug.h
    IDENTIFIER KROSS_QTS_PLUGIN_LOG
    CATEGORY_NAME org.kde.kross.qts_plugin
)
add_library(krossqtsplugin MODULE ${krossqtsplugin_LIB_SRCS})
target_link_libraries(krossqtsplugin
    KF5::I18n
    KF5::KrossCore
    Qt5::UiTools
    Qt5::Script
    Qt5::Widgets
    Qt5::Gui
    Qt5::Core
)

install(TARGETS krossqtsplugin DESTINATION ${KDE_INSTALL_QTPLUGINDIR}/script)
