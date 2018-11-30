# Este programa se ejecuta en la consola Python de FreeCAD con el comando "execfile(/carpeta/*.py)". Este archivo en particular permite mover los componentes con las funciones de la libreria C++
import FreeCAD as App
import FreeCADGui as Gui
from PyQt4 import QtCore, QtGui

import math

# execfile("/home/carlos/Documents/Universidad/sensores/programas/piston/test.py")
FreeCAD.open("/home/carlos/Documents/Universidad/sensores/programas/piston/piston.fcstd")
App.setActiveDocument("piston")
App.ActiveDocument=App.getDocument("piston")
Gui.ActiveDocument=Gui.getDocument("piston")
import sys
sys.path.append('/home/carlos/Documents/Universidad/sensores/programas/piston/')
import MoveModule

move=MoveModule.pMovement()
PI = 3.14159
w0=0
t=0
xt=0

def Leonardo():
     global PI, move, w0, w1, xt, t

     t+=0.1
     if t>40:
     	t=0

     move.resorteamortiguador(t,1.0465,0.7,1,.15,.2)
     move.resorteamortiguador1(t,1.5465,0.31,1,.15,.2)
     xt=move.ResultXT
     xt1=move.ResultXT1
     App.getDocument("piston").Part__Feature001.Placement=App.Placement(App.Vector(35+(xt*1000),0,0), App.Rotation(0,90,0), App.Vector(0,0,0))
     App.getDocument("piston").Part__Feature003.Placement=App.Placement(App.Vector(1334+(xt*1000),0,0), App.Rotation(0,-90,0), App.Vector(0,0,0))
     App.getDocument("piston").Part__Feature004.Placement=App.Placement(App.Vector(1356+(xt1*1000),400,0), App.Rotation(0,-90,0), App.Vector(0,0,0))
     App.getDocument("piston").Part__Feature006.Placement=App.Placement(App.Vector(35+(xt1*1000),400,0), App.Rotation(0,90,0), App.Vector(0,0,0))

timer=QtCore.QTimer()
timer.timeout.connect(Leonardo)
timer.start(10)
