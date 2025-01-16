# Nombre del ejecutable
EXEC = p06_automata_simulator

# Archivos fuente
SRC = Alfabeto.cc Automata.cc Estado.cc Funciones.cc Cadena.cc Main.cc

# Regla para compilar el ejecutable
$(EXEC): $(SRC)
	g++ -o $(EXEC) $(SRC)

# Limpiar los archivos generados
clean:
	rm -f $(EXEC) *.o