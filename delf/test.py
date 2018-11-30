# Este programa se ejecuta en la consola Python de FreeCAD con el comando "execfile(/carpeta/*.py)". Este archivo en particular permite mover los componentes con las funciones de la libreria C++
import FreeCAD as App
import FreeCADGui as Gui
from PyQt4 import QtCore, QtGui

import math
import time

# execfile("/home/carlos/Documents/Universidad/sensores/programas/delf/test.py")
FreeCAD.open("/home/carlos/Documents/Universidad/sensores/programas/delf/delfin.fcstd")
App.setActiveDocument("delfin")
App.ActiveDocument=App.getDocument("delfin")
Gui.ActiveDocument=Gui.getDocument("delfin")
import sys
sys.path.append('/home/carlos/Documents/Universidad/sensores/programas/delf/')
import MoveModule

move=MoveModule.pMovement()
PI = 3.14159
w0=0
t=0
phi1=0
phi2=0
phi3=0
t1 = 0
t2 = 0

def Leonardo():
     global PI, move, w0, w1, phi1,phi2,phi3, t, t1, t2

     t+=1
     if t==50:
	t=0

     move.delfin(0)
     phi1 = move.Resultphi1
     phi2 = move.Resultphi2
     phi3 = move.Resultphi3
     App.getDocument("delfin").Part__Feature001.Placement=App.Placement(App.Vector(0,0,0), App.Rotation(phi1,0,0), App.Vector(0,0,0))
     App.getDocument("delfin").Part__Feature002.Placement=App.Placement(App.Vector(700*math.cos(math.radians(phi1)),700*math.sin(math.radians(phi1)),0), App.Rotation(phi2,0,0), App.Vector(0,0,0))
     App.getDocument("delfin").Part__Feature003.Placement=App.Placement(App.Vector((518.75*math.cos(math.radians(phi2)) + (700*math.cos(math.radians(phi1)))) , (518.75*math.sin(math.radians(phi2)) + (700*math.sin(math.radians(phi1)))),0), App.Rotation(phi3,0,0), App.Vector(0,0,0))

     time.sleep(10)

timer=QtCore.QTimer()
timer.timeout.connect(Leonardo)
timer.start(10)
