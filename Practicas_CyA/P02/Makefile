# Nombre del ejecutable
EXEC = p02_strings

# Archivos fuente
SRC = Cliente.cc Lenguaje.cc Functions.cc Alfabeto.cc Cadena.cc

# Regla para compilar el ejecutable
$(EXEC): $(SRC)
	g++ -o $(EXEC) $(SRC)

# Limpiar los archivos generados
clean:
	rm -f $(EXEC) *.o