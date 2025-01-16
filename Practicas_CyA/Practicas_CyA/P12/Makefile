# Nombre del ejecutable
EXEC = p12_quickhull

# Archivos fuente
SRC = functions.cc PointSet.cc main.cc

# Regla para compilar el ejecutable
$(EXEC): $(SRC)
	g++ -o $(EXEC) $(SRC)

# Limpiar los archivos generados
clean:
	rm -f $(EXEC) *.o