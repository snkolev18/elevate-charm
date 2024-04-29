make:
	gcc python-sudo.c -o python-sudo
	sudo chown root python-sudo
	sudo chmod 4775 python-sudo
clean:
	rm python-sudo
	
