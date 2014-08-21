#!/bin/sh -x

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
    DESTDIR_ARG="--root=$DESTDIR"
fi

cd "/home/lars/OculusCamViewer_new/src/robotcamera/rqt_ops"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
/usr/bin/env \
    PYTHONPATH="/home/lars/OculusCamViewer_new/install/lib/python2.7/dist-packages:/home/lars/OculusCamViewer_new/build/lib/python2.7/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/lars/OculusCamViewer_new/build" \
    "/usr/bin/python" \
    "/home/lars/OculusCamViewer_new/src/robotcamera/rqt_ops/setup.py" \
    build --build-base "/home/lars/OculusCamViewer_new/build/robotcamera/rqt_ops" \
    install \
    $DESTDIR_ARG \
    --install-layout=deb --prefix="/home/lars/OculusCamViewer_new/install" --install-scripts="/home/lars/OculusCamViewer_new/install/bin"
