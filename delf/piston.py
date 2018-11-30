# Este programa se ejecuta en la consola Python de FreeCAD con el comando "execfile(/carpeta/*.py)". Este archivo en particular permite mover los componentes con las funciones de la libreria C++
import FreeCAD as App
import FreeCADGui as Gui
from PyQt4 import QtCore, QtGui

import math
import time

# execfile("/home/carlos/Documents/Universidad/sensores/programas/delf/piston.py")
FreeCAD.open("/home/carlos/Documents/Universidad/sensores/programas/delf/pistones.fcstd")
App.setActiveDocument("pistones")
App.ActiveDocument=App.getDocument("pistones")
Gui.ActiveDocument=Gui.getDocument("pistones")
import sys
sys.path.append('/home/carlos/Documents/Universidad/sensores/programas/delf/')
import MoveModule

move=MoveModule.pMovement()
PI = 3.14159
w0=0
t=0
kt = 1.0465
ct = .7

def Leonardo():
     global PI, move, w0, w1, phi1,phi2,phi3, t, t1, t2,kt,ct

     t+=1
     if t==50:
	t=0

     move.resorteamortiguador(t,1.0465,0.7,2,0.15,0.2)
     w0 = move.ResultXT

     App.getDocument("pistones").Part__Feature001.Placement=App.Placement(App.Vector(0,0,0), App.Rotation(-30,90,0), App.Vector(0,0,0))

     time.sleep(10)

timer=QtCore.QTimer()
timer.timeout.connect(Leonardo)
timer.start(10)
