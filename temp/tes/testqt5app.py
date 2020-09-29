from tesqt5designer import *
import sys  


class testqt5(Ui_MainWindow):
    def __init__(self, window):
        self.setupUi(window)
        #init
        self.labels1.setText("Joint 1 Angle: "+str(self.hslider1.value())+u'\N{DEGREE SIGN}')
        self.labels2.setText("Joint 2 Angle: "+str(self.hslider2.value())+u'\N{DEGREE SIGN}')
        self.labels3.setText("Joint 3 Angle: "+str(self.hslider3.value())+u'\N{DEGREE SIGN}') 

        #process
        self.pushButton1.clicked.connect(self.showName1)
        self.pushButton2.clicked.connect(self.showName2)
        self.hslider1.valueChanged.connect(self.s1label)
        self.hslider2.valueChanged.connect(self.s2label)
        self.hslider3.valueChanged.connect(self.s3label)

    def clickMe(self):
        print("hellow dunia")
    def showName1(self):
        self.label1.setText("indra agustian")
    def showName2(self):
        self.label1.setText("apa kabar??")
    def s1label(self):
        self.labels1.setText("Joint 1 Angle: "+str(self.hslider1.value())+u'\N{DEGREE SIGN}')
    def s2label(self):
        self.labels2.setText("Joint 2 Angle: "+str(self.hslider2.value())+u'\N{DEGREE SIGN}')
    def s3label(self):
        self.labels3.setText("Joint 3 Angle: "+str(self.hslider3.value())+u'\N{DEGREE SIGN}')    


app = QtWidgets.QApplication(sys.argv)
MainWindow=QtWidgets.QMainWindow()
ui=testqt5(MainWindow)
MainWindow.show()
app.exec_()

