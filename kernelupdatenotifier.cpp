/* PLD Linux Kernel Update Notifier
 * author: Bartosz 'shadzik' Świątek (shadzik@pld-linux.org)
 * license: GPLv2+
 * (c) 2009
 *
 * Thanks to Piotr 'vip' Budny for a Qt4 crash course ;)
 *
 */

#include <QApplication>
#include <QObject>
#include <QProcess>
#include <QTextDocument>
#include <QPixmap>

#include <knotification.h>
#include <klocale.h>
#include <kdebug.h>
#include <qdebug.h>
#include <kworkspace/kworkspace.h>
#include <KStandardDirs>

#include "kernelupdatenotifier.h"

void KernelUpdateNotifier::handleRebootAction(uint action)
{
	KNotification *notify = (KNotification *) sender();
	kDebug()<<"Reboot"<<action;
	switch(action)
	{
		case 1:
			KWorkSpace::ShutdownConfirm confirm = KWorkSpace::ShutdownConfirmYes;
			KWorkSpace::ShutdownType type = KWorkSpace::ShutdownTypeReboot;
			KWorkSpace::ShutdownMode mode = KWorkSpace::ShutdownModeInteractive;
			KWorkSpace::requestShutDown(confirm, type, mode);
			break;
	}
	notify->close();
	QApplication::quit();
}

void KernelUpdateNotifier::handleRebootActionClosed()
{
	kDebug() << "Don't Reboot";
	QApplication::quit();
}

void KernelUpdateNotifier::sendNotify(const QString &version)
{
	KNotification *notify = new KNotification("KernelWasUpgraded", 0, KNotification::Persistent);

	QString text;
	text =  i18n("The Kernel was upgraded to version:") + "<br/>";
	text += "<b>" + version + "<b><br/>";
	text += i18n("Please reboot the machine.");
	notify->setText(text);

	QStringList actions;
	actions << i18n("Reboot Now!");
	actions << i18n("Cancel");
	notify->setActions(actions);

	connect(notify, SIGNAL(activated(uint)),
		this, SLOT(handleRebootAction(uint)));
	//connect(notify, SIGNAL(closed()),
	connect(notify, SIGNAL(activated(uint)),
		this , SLOT(handleRebootActionClosed()));

	notify->sendEvent();
}

