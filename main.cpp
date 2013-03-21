/* PLD Linux Kernel Update Notifier
 * author: Bartosz 'shadzik' Świątek (shadzik@pld-linux.org)
 * license: GPLv2+
 * (c) 2009
 *
 * Thanks to Piotr 'vip' Budny for a Qt4 crash course ;)
 *
 */

#include <QObject>
#include <QApplication>

#include "kernelupdatenotifier.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	KernelUpdateNotifier *aps = new KernelUpdateNotifier();
	aps->sendNotify(argv[1]);
	return app.exec();
}

