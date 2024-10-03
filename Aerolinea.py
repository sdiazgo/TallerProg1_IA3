import random

def generar_vuelo(vuelo_num):
    # Genera aleatoriamente el número de pasajeros (entre 50 y 100)
    num_pasajeros = random.randint(50, 100)
    
    # Genera aleatoriamente la distancia del vuelo (entre 500 y 5000 kilómetros)
    distancia = random.randint(500, 5000)
    
    print(f"\nVuelo {vuelo_num}: {num_pasajeros} pasajeros, Distancia: {distancia} km")
    
    # Listas separadas para almacenar los IDs de los pasajeros y sus millas
    codigos_pasajeros = []
    millas_pasajeros = []

    # Para cada pasajero, generamos su ID y calculamos sus millas
    for i in range(1, num_pasajeros + 1):
        codigo_pasajero = random.randint(100, 999)
        millas_base = distancia
        
        # Determinar si es VIP o Diamante
        if codigo_pasajero % 12 == 0:
            estatus = "Diamante"
            millas_extra = distancia / 20
        elif codigo_pasajero % 7 == 0:
            estatus = "VIP"
            millas_extra = distancia / 60
        else:
            estatus = "Normal"
            millas_extra = distancia / 100
        
        millas_totales = millas_base + millas_extra
        
        # Guardamos el código del pasajero y sus millas en listas separadas
        codigos_pasajeros.append(codigo_pasajero)
        millas_pasajeros.append(millas_totales)

        # Imprimir información del pasajero
        print(f"  Pasajero {codigo_pasajero} - Estatus: {estatus} - Millas totales: {millas_totales:.2f}")
    
    # Retornar las listas por si se requieren después
    return codigos_pasajeros, millas_pasajeros

def main():
    while True:
        try:
            # Solicitar al usuario el número de vuelos
            n = int(input("Ingrese el número de vuelos a generar (n > 0): "))
            if n > 0:
                break
            else:
                print("Por favor, ingrese un número mayor que cero.")
        except ValueError:
            print("Entrada no válida. Por favor ingrese un número entero.")

    # Generar n vuelos
    for vuelo in range(1, n + 1):
        codigos_pasajeros, millas_pasajeros = generar_vuelo(vuelo)
        
        # Imprimir las listas de códigos y millas de cada vuelo
        print(f"\nCódigos de pasajeros del Vuelo {vuelo}: {codigos_pasajeros}")
        print(f"Millas de pasajeros del Vuelo {vuelo}: {millas_pasajeros}")

if __name__ == "__main__":
    main()
