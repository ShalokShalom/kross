/***************************************************************************
 * plugin.h
 * This file is part of the KDE project
 * copyright (C)2007 by Sebastian Sauer (mail@dipe.org)
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 * You should have received a copy of the GNU Library General Public License
 * along with this program; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 ***************************************************************************/

#ifndef KROSS_ECMAPLUGIN_H
#define KROSS_ECMAPLUGIN_H

#include <QtScript/QScriptEngine>
#include <QtScript/QScriptExtensionPlugin>
//#include <QtCore/QVariant>
//#include <QtCore/QObject>
//#include <QtCore/QDir>
//#include <QtXml/QDomAttr>
//#include <QAction>
//#include <QtCore/QUrl>

//#include "errorinterface.h"
//#include "childreninterface.h"

#define KROSSQTSPLUGIN_EXPORT Q_DECL_EXPORT

namespace Kross
{

/**
* Kross QtScript Extension that provides access to the Kross Scripting Framework
* within the QtScript scripting language. This EcmaPlugin does implement the
* extension named "kross".
*/
class KROSSQTSPLUGIN_EXPORT EcmaPlugin : public QScriptExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.kde.EcmaPlugin")
public:

    /**
    * Constructor.
    *
    * \param parent Optional QObject parent of this QObject.
    */
    EcmaPlugin(QObject *parent = nullptr);

    /**
    * Destructor.
    */
    virtual ~EcmaPlugin();

    /**
    * Initializes this extension.
    *
    * \param key The key to differ between etensions. We provide
    * the extension which key is "kross".
    * \param engine The QScriptEngine instance.
    */
    void initialize(const QString &key, QScriptEngine *engine) Q_DECL_OVERRIDE;

    /**
    * Returns the list of keys this plugin supports.
    *
    * \return a QStringList with the single item "kross" to let
    * QtScript know, that we provide an extension with that key.
    */
    QStringList keys() const Q_DECL_OVERRIDE;

private:
    /// \internal d-pointer class.
    class Private;
    /// \internal d-pointer instance.
    Private *const d;
};

}

#endif

