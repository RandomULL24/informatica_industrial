#Autor: Alberto Hamilton Castro
#Fichero Makefile para compilar las distintas pruebas
# preparadas para verificar el correcto funcionamiento
# del ejercicio
#
# basta con ejecutar en línea de comandos
#  make  ->  para compilar las pruebas básica
#  make prueba##  -> para obtener ese ejecutable concreto (no poner cpp)
#  make clean -> borrar ficheros generados y dejar solo los fuentes
#  make exe## -> trata de compilar y ejecutar la prueba##
#  make exe -> trata de compilar y ejecutar todas las pruebas
#  make fallidas -> ídem que la anterior pero sólo muestra resultado
#      de las fallidas


GPP=g++ -g -Wall --std=c++14

pruebas:=$(wildcard prueba[0-8]?.cpp)

ejecutables:=$(wildcard prueba*.cpp)


clases:=$(wildcard [A-Z]*.cpp)

fichero1Zip=FicherosP2_E1.zip
pruebas1Zip:=$(wildcard prueba[0-3,6]?.cpp)

fichero2Zip=FicherosP2_E2.zip
pruebas2Zip:=$(wildcard prueba[4-5,7]?.cpp)

zips=$(fichero1Zip) $(fichero2Zip)

#Evitamos que se borren los fichero intermedios (%.o)
.SECONDARY :

all : $(pruebas:.cpp=)

info :
	@echo "\npruebas: $(pruebas)"
	@echo "\nejecutables: $(ejecutables)"
	@echo "\nclases: $(clases)"
	@echo "\npruebasZip: $(pruebasZip)"


depend : .dependC .dependP .dependE

.dependC: $(clases) Makefile
	@rm -f ./.dependC
	@$(GPP)  -MM $(clases) > ./.dependC 2>/dev/null

.dependP: $(ejecutables) $(clases) Makefile
	@rm -f ./.dependP
	@$(GPP)  -MM $(ejecutables) > ./.dependP 2>/dev/null

.dependE: .dependP
	@rm -f ./.dependE
	@cat ./.dependP | sed -e's/\.o//' -e's/\..pp/\.o/g' > ./.dependE


-include .dependC
-include .dependP
-include .dependE

%.o : %.cpp
	-rm -f $@  $(@:.o=)
	$(GPP) -c -o $@ $<

prueba% : prueba%.o
	$(GPP) -lrt -lpthread -g -o $@ $^

#reglas para borrar los fichero generados
# y dejar sólo los fuente
clean :
	rm -f *.o $(ejecutables:.cpp=) .depend* *.hpp.gch resumen.log core ejecucion.log $(zips)

#Generación de zip
zip : $(zips)

$(fichero1Zip) : Makefile $(pruebas1Zip)
	-rm $@
	zip $@ $^

$(fichero2Zip) : Makefile $(pruebas2Zip)
	-rm $@
	zip $@ $^

#Reglas para ejecutar los distintos grupos de pruebas

exe% : prueba%
	@ulimit -v 60000; \
	ulimit -t 6; \
	./$<

exe :  $(sort $(pruebas:.cpp=))
	@for fa in $^; \
	do echo "\n$$(tput setaf 2)==== $$fa ===========================$$(tput sgr0)"; \
	ulimit -v 60000; ulimit -t 6; \
	./$$fa;done

fallidas :   $(sort $(pruebas:.cpp=))
	@for fa in $^; \
	do ulimit -v 60000; ulimit -t 6; \
	if ./$$fa >/dev/null 2>&1; \
	then echo "==== "$$fa CORRECTA""; \
	else echo "\n$$(tput setaf 2)==== $$fa ===========================$$(tput sgr0)"; \
	./$$fa; fi; done


fallan :
	-make clean
	make fail

fail:
	@echo "\n==========================="
	@for fa in $(sort $(pruebas:.cpp=)); \
	do titulo=$$(grep 'define TITULO' $$fa.cpp | sed -e's/^#define TITULO //'); \
	make -k $$fa  >/dev/null 2>&1; \
	if [ $$? -ne 0 ] ; \
	then \
	  rm -f $$fa >/dev/null 2>&1; \
	  echo "$$(tput setaf 1)==== $$fa NO EXISTE  $$titulo $$(tput sgr0)"; \
	else \
	  {( ulimit -v 60000; ulimit -t 6; ./$$fa >ejecucion.log 2>&1 ) ; RES=$$?; } 2>>ejecucion.log; \
	  if [ $$RES -eq 0 ] ; \
	  then echo "$$(tput setaf 2)==== $$fa CORRECTA   $$titulo $$(tput sgr0)"; \
	  else \
	    if egrep -a -w -q '(core|Segmentation|Aborted)' ejecucion.log ; \
	    then \
	      PORCEN="(core)" ;\
	    else \
	      PORCEN=$$(cat ejecucion.log | grep -a 'pruebas.*%' | sed -e's/^.*pruebas //'); \
	    fi; \
	    echo "$$(tput setaf 5)==== $$fa INCORRECTA $$PORCEN $$titulo $$(tput sgr0)"; \
	  fi; \
	fi; done
	@rm -f ejecucion.log
	@echo "===========================\n"

resumen.log: $(clases) $(clases:.cpp=.hpp) Makefile
	@rm -f resumen.log
	@for fa in $(sort $(pruebas:.cpp=)); \
	do echo -n $$(echo $$fa | sed -e's/prueba//'):  >> resumen.log;\
	make -k $$fa  >/dev/null 2>&1; \
	if [ $$? -ne 0 ] ; \
	then \
	  rm -f $$fa >/dev/null 2>&1; \
	  echo " --- " >> resumen.log; \
	else \
	  {( ulimit -v 60000; ulimit -t 6; ./$$fa >ejecucion.log 2>&1 ) ; RES=$$?; } 2>>ejecucion.log; \
	  if [ $$RES -eq 0 ] ; \
	  then echo " 100 " >> resumen.log; \
	  else \
	    if egrep -a -w -q '(core|Segmentation|Aborted)' ejecucion.log ; \
	    then \
	      echo "core " >> resumen.log; \
	    else \
	      PORCEN=$$(cat ejecucion.log | grep -a 'pruebas.*%' | sed -e's/^.*pruebas .//' -e's/. .*xito.*$$//'); \
	      printf " %3d \n" $$PORCEN >> resumen.log; \
	    fi; \
	  fi; \
	fi; done
	@rm -f ejecucion.log
