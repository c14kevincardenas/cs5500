help:
	@echo "Available commands:"
	@echo "- my-list-forming"
	@echo "- substring-threads"
	@echo "- substring-sequential"
	@echo "- condition-variable"

my-list-forming:
	for name in my_list-forming_*.c ; do \
		echo "\n"$$name; \
		gcc -g $$name -o my_list-forming -pthread -D_GNU_SOURCE ; \
		for i in 1 2 3 ; do \
			echo "Run #"$$i ; \
			for threads in 2 4 8 16 32 64 ; do \
				for k in 200 400 800 ; do \
					# echo "Threads =" $$threads "| K =" $$k ; \
					./my_list-forming $$threads $$k ; \
				done ; \
			done ; \
		done ; \
	echo "Program" $$name "ran for 2, 4, 8, 16, 32, 64 threads and k = 200, 400, 800.\n" ; \
	done


substring-threads:
	gcc -pthread -g substring_threads.c -o substring_threads
	./substring_threads


substring-sequential:
	gcc -g substring_sequential.c -o substring_sequential
	./substring_sequential

condition-variable:
	gcc -g -pthread condvars.c -o condvars
	./condvars