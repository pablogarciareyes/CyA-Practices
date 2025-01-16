# Nombre del ejecutable
EXEC = p11_kruskal

# Archivos fuente
SRC = functions.cc point_set.cc point_types.cc sub_tree.cc main.cc

# Regla para compilar el ejecutable
$(EXEC): $(SRC)
	g++ -o $(EXEC) $(SRC)

# Limpiar los archivos generados
clean:
	rm -f $(EXEC) *.o