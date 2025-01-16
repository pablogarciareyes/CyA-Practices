# Nombre del ejecutable
EXEC = p08_grammar2CNF

# Archivos fuente
SRC = alfabeto.cc gramatica.cc produccion.cc grammar2CNF.cc funciones.cc

# Regla para compilar el ejecutable
$(EXEC): $(SRC)
	g++ -o $(EXEC) $(SRC)

# Limpiar los archivos generados
clean:
	rm -f $(EXEC) *.o