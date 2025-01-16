# Nombre del ejecutable
EXEC = p04_code_analyzer

# Archivos fuente
SRC = Functions.cc Main.cc Storage.cc

# Regla para compilar el ejecutable
$(EXEC): $(SRC)
	g++ -o $(EXEC) $(SRC)

# Limpiar los archivos generados
clean:
	rm -f $(EXEC) *.o