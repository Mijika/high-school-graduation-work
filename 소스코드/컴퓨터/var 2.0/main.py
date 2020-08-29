import sys


class mainWindow(QWidget):
	def __init__(self, parent=None):
		QWidget.__init__(self, flags=Qt.Widget)
		self.size


def main():
	app = QApplication(sys.argv)
	window = mainWindow()
	sys.exit(app.exec_())

if __name__ == '__main__':
	main()