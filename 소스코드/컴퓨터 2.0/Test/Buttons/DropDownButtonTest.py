if __name__ == '__main__':
	import os
	import sys
	from PyQt5.QtWidgets import QApplication, QWidget, QHBoxLayout
	os.chdir('../')
	os.chdir('../')
	sys.path.append(os.getcwd())

	from Widgets.Buttons.DropDownButton import DropDownButton


	app = QApplication(sys.argv)
	app.setStyleSheet("""
	DropDownButton {
		min-width: 200px;
		max-width: 200px;
		min-height: 200px;
		max-height: 200px;
		border: none;
		color: white;
		outline: none;
		margin: 4px;
		text-align:center;
		font-size: 48px;
		qproperty-bgColor: rgba(255, 0, 0, 150);
	}
	""")
	w = QWidget()
	w.resize(400, 400)
	layout = QHBoxLayout(w)
	layout.addWidget(DropDownButton('hello', w))
	w.show()
	sys.exit(app.exec_())