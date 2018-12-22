#!/bin/bash

/home/doohoyi/Runtime/Qt/Tools/QtCreator/bin/qbs build -d /home/doohoyi/qtcreator-projects/of_v20181009_linux64gcc6_release/apps/myApps/build-mario-Desktop-Release -f /home/doohoyi/qtcreator-projects/of_v20181009_linux64gcc6_release/apps/myApps/mario/mario.qbs --settings-dir /home/doohoyi/.config/QtProject/qtcreator --jobs 2 config:qtc_Desktop_Release qbs.defaultBuildVariant:release profile:qtc_Desktop_b80f0566 && ./home/doohoyi/qtcreator-projects/of_v20181009_linux64gcc6_release/apps/myApps/mario/bin/mario
