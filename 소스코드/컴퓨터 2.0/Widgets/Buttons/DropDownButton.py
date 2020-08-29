from PyQt5.QtCore import *
from PyQt5.QtGui import *
from PyQt5.QtWidgets import *


class DropDownMenu(QWidget):
	def __init__(self, parent=None):
		super(DropDownMenu, self).__init__(parent)
		self.setWindowFlags(Qt.Popup)

		self.parent = parent
		self._closeMenu = False

		self._width = 0
		self._height = 0

		self._VLayoutMenu = QVBoxLayout(self)
		self._VLayoutMenu.setContentsMargins(0, 0, 0, 0)
		self._VLayoutMenu.setSpacing(0)

		sizePolicy = QSizePolicy(QSizePolicy.Expanding, QSizePolicy.Expanding)
		sizePolicy.setHorizontalStretch(0)
		sizePolicy.setVerticalStretch(0)
		self.setSizePolicy(sizePolicy)

	def addItem(self, btn):
		self._VLayoutMenu.addWidget(btn)


	def resizing(self, width, height):
		self._width = width
		self._height = height * self._VLayoutMenu.count()

		self.setMinimumSize(self._width, self._height)
		self.setMaximumSize(self._width, self._height)

	def animationShow(self):
		self._closeMenu = False
		self.startCloseMenu = True

		rect = self.parent.rect()
		center_pos = rect.center()
		global_center_pos = self.parent.mapToGlobal(QPoint(0,0))
		height = rect.height()

		show_pos = QPoint(
			global_center_pos.x(),
			global_center_pos.y() + height-1)

		self.move(show_pos)
		self.show()
		self.inAnimation()

	def inAnimation(self):
		startHeight = QSize(self._height, 0)
		endHeight = QSize(self._height, self._height)

		sizeAnim = QPropertyAnimation(self, b'size')
		sizeAnim.setStartValue(startHeight)
		sizeAnim.setEndValue(endHeight)
		sizeAnim.setDuration(160)
		sizeAnim.setEasingCurve(QEasingCurve.OutQuad)

		opacityAnim = QPropertyAnimation(self, b'windowOpacity')
		opacityAnim.setStartValue(0.0)
		opacityAnim.setEndValue(1.0)
		opacityAnim.setDuration(260)
		opacityAnim.setEasingCurve(QEasingCurve.OutQuad)

		self.inAnimGroup = QParallelAnimationGroup()
		self.inAnimGroup.addAnimation(sizeAnim)
		self.inAnimGroup.addAnimation(opacityAnim)
		self.inAnimGroup.start()

	def outAnimation(self):
		try:
			endSize = QSize(self._width, 0)

			posAnim = QPropertyAnimation(self, b'size')
			posAnim.setEndValue(endSize)
			posAnim.setDuration(200)
			posAnim.setEasingCurve(QEasingCurve.InQuad)

			opacityAnim = QPropertyAnimation(self, b'windowOpacity')
			opacityAnim.setStartValue(1.0)
			opacityAnim.setEndValue(0.0)
			opacityAnim.setDuration(200)
			opacityAnim.setEasingCurve(QEasingCurve.InQuad)

			self.outAnimGroup = QParallelAnimationGroup()
			self.outAnimGroup.addAnimation(posAnim)
			self.outAnimGroup.addAnimation(opacityAnim)
			self.outAnimGroup.finished.connect(self.closeMenu)
			self.outAnimGroup.start()

		except RuntimeError as e:
			pass
		except Exception as e:
			print(e)

	def closeMenu(self):
		self._closeMenu = True
		self.setVisible(False)

	def closeEvent(self, event):
		super(DropDownMenu, self).closeEvent(event)
		if self.startCloseMenu:
			self.outAnimation()
			self.startCloseMenu = False

	def hideEvent(self, event):
		# print 'hideEvent', event
		super(DropDownMenu, self).hideEvent(event)

	def setVisible(self, visible):
		if self._closeMenu:
			visible = False

		elif not visible:
			visible = True

		super(DropDownMenu, self).setVisible(visible)

class DropDownButton(QPushButton):
	def __init__(self, *args, **kwargs):
		super(DropDownButton, self).__init__(*args, **kwargs)
		# self.setFlat(True)
		self.setCursor(Qt.PointingHandCursor)

		self._menu = DropDownMenu(self)

		self.clicked.connect(self._menu.animationShow)
		self.setSizePolicy(QSizePolicy.Expanding, QSizePolicy.Expanding)

	def addMenu(self, btn):
		self._menu.addItem(btn)

	def resizeEvent(self, event):
		self._width = self.width()
		self._height = self.height()

		self._menu.resizing(self._width, self._height)

	def setStyle(self):
		StyleSheet = """

		"""

		self.setStyleSheet(StyleSheet)

class Win(QWidget):
	"""docstring for Win"""
	def __init__(self):
		super(Win, self).__init__()

		vbox = QVBoxLayout(self)
		btn = DropDownButton('call menu')

		btn1 = QPushButton("asd1")
		btn2 = QPushButton("asd2")
		btn3 = QPushButton("asd3")

		btn.addMenu(btn1)
		btn.addMenu(btn2)
		btn.addMenu(btn3)

		vbox.addWidget(btn)
		vbox.setContentsMargins(0, 0, 0, 0)
		self.resize(800, 100)

	def printasd(self):
		print("asdg")


if __name__ == '__main__':
	import sys
	app = QApplication(sys.argv)
	win = Win()
	win.show()
	sys.exit(app.exec_())