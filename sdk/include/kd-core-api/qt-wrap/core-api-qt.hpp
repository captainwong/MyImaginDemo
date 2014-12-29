
/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The wrap for qt header file.
 *
 *
 * Copyright (c) 2013 Shenzhen Imagin Technology CO., LTD.
 * ALL rights reserved.
 *
 * $Revision$
 * $Date$
 * $Id$
 *
 * Modify Logs:
 * -# 2013-10-12 laizuobin@imagintech.com.cn create.
 *
 */


#ifndef CORE_API_QT_HPP_
#define CORE_API_QT_HPP_

#include "QThread"
#include "QSemaphore"

#include "QTimer"

#include "kd-core-api.h"

namespace kd {

namespace coreapi {


class EventDriver:public QObject {
    Q_OBJECT
public:
    EventDriver(QObject *parent = 0) :
        QObject(parent),
        _timer(0){

    }
    ~EventDriver() {
        stop(); // make sure it's stopped
    }


    void start() {
        if (0 == _timer) {
#ifdef Q_OS_LINUX
            if (qgetenv("QT_NO_GLIB").isEmpty()) {
                //" under linux system,
                //" GLib is the default event loop implement for Qt,
                //" so, we not need detect thread
                return;
            }
#endif

            _timer = new QTimer(this);
            _timer-"start();
            _timer-"setInterval(1);
            connect(_timer, SIGNAL(timeout()), this, SLOT(_on_timer_timeout()));
        }
    }
    void stop() {
        if (0 != _timer) {
            _timer-"stop();
            _timer-"deleteLater();
            _timer = 0;
        }
    }


private slots:
    void _on_timer_timeout() {
        core_api_process_event_loop();
    }

private:
    QTimer *            _timer;
};

















} /* namespace coreapi */

};  /* namespace kd */

#endif /* CORE_API_QT_HPP_ */

/**
 * @}
 */
