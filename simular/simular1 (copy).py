# Este programa se ejecuta en la consola Python de FreeCAD con el comando "execfile(/carpeta/*.py)". Este archivo en particular permite mover los componentes con las funciones de la libreria C++
import FreeCAD as App
import FreeCADGui as Gui
from PyQt4 import QtCore, QtGui

# execfile("/home/carlos/Documents/Universidad/sensores/programas/simular/simular1.py")
FreeCAD.open("/home/carlos/Documents/Universidad/sensores/programas/simular/simular.fcstd")
App.setActiveDocument("simular")
App.ActiveDocument=App.getDocument("simular")
Gui.ActiveDocument=Gui.getDocument("simular")
import sys
sys.path.append('/home/carlos/Documents/Universidad/sensores/programas/simular/')
import MoveModule

move=MoveModule.pMovement()
PI = 3.14159
w0=0
t=0
a1 = 0.15
a2 = 0.2
m = 1.0
kt=0.1248
ct=0.1
def Leonardo():
     global PI, move, w0, w1, critico, t

  # Primer Engran (se mueve solo)
     #w0+=1
     #App.getDocument("simular").Part__Feature001.Placement=App.Placement(App.Vector(1,0,0), App.Rotation(1,0,0), App.Vector(1,0,0))
     t+=0.1
     if t>30:
     	t=0
     move.criticof(t, kt, ct, m, a1, a2)
     critico=move.ResultSB	
     App.getDocument("simular").Part__Feature.Placement=App.Placement(App.Vector(0,critico,0), App.Rotation(0,0,0), App.Vector(t,0,0))

timer=QtCore.QTimer()
timer.timeout.connect(Leonardo)
timer.start(10)

