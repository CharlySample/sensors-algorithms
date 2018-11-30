# Este programa se ejecuta en la consola Python de FreeCAD con el comando "execfile(/carpeta/*.py)". Este archivo en particular permite mover los componentes con las funciones de la libreria C++
import FreeCAD as App
import FreeCADGui as Gui
from PyQt4 import QtCore, QtGui

import math

# execfile("/home/carlos/Documents/Universidad/sensores/programas/simular/test.py")
FreeCAD.open("/home/carlos/Documents/Universidad/sensores/programas/simular/simularo.fcstd")
App.setActiveDocument("simularo")
App.ActiveDocument=App.getDocument("simularo")
Gui.ActiveDocument=Gui.getDocument("simularo")
import sys
sys.path.append('/home/carlos/Documents/Universidad/sensores/programas/simular/')
import MoveModule

move=MoveModule.pMovement()
PI = 3.14159
w0=0
t=0
xt=0

def Leonardo():
     global PI, move, w0, w1, xt, t

     t+=0.1
     if t>20:
     	t=0

     move.resorteamortiguador(t,0.1248,.91,1,.15,.2)
     xt=move.ResultXT
     App.getDocument("simularo").Part__Feature003.Placement=App.Placement(App.Vector(-96,xt*100,4), App.Rotation(0,0,0), App.Vector(t,0,0))

     move.resorteamortiguador(t,0.1248,.1,1,.15,.2)
     xt=move.ResultXT
     App.getDocument("simularo").Part__Feature005.Placement=App.Placement(App.Vector(103,xt*100,4), App.Rotation(0,0,0), App.Vector(t,0,0))
 
     help = math.sqrt(0.1248*4)

     move.resorteamortiguador(t,0.1248,0.7065408693,1,.15,.2)
     xt=move.ResultXT
     App.getDocument("simularo").Part__Feature004.Placement=App.Placement(App.Vector(0,xt*100,4), App.Rotation(0,0,0), App.Vector(t,0,0))

timer=QtCore.QTimer()
timer.timeout.connect(Leonardo)
timer.start(10)
