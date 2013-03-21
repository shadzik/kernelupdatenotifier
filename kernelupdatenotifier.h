/* PLD Linux Kernel Update Notifier
 * author: Bartosz 'shadzik' Świątek (shadzik@gmail.com)
 * license: GPLv2+
 * (c) 2009
 *
 * Thanks to Piotr 'vip' Budny for a Qt4 crash course ;)
 *
 */

#include <QObject>

#ifndef KERNELUPDATENOTIFIER_H
#define KERNELUPDATENOTIFIER_H

class KernelUpdateNotifier: public QObject
{
	Q_OBJECT

	private slots:
		void handleRebootAction(uint action);
		void handleRebootActionClosed();

	public:
		void sendNotify(const QString &version);

//private:
//        KNotification *notify;

};

#endif

