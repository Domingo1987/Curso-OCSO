import multiprocessing
import time

def worker(name, tiempo):
    print("Proceso " + name + " iniciando... ")
    time.sleep(tiempo)  # Simula un trabajo que tarda 2 segundos
    print("Proceso " + name + " finalizando... ")

if __name__ == "__main__":
    # Crear dos procesos
    p1 = multiprocessing.Process(target=worker, args=('P1', 10, ))
    p2 = multiprocessing.Process(target=worker, args=('P2', 20, ))
    p3 = multiprocessing.Process(target=worker, args=('P3', 10, ))

    print('Iniciando procesos...')
    p1.start()  # Iniciar el primer proceso
    p2.start()  # Iniciar el segundo proceso
    p3.start()  # Iniciar el segundo proceso


    print('Esperando a que los procesos terminen...')
    p1.join()  # Esperar a que termine el primer proceso
    p2.join()  # Esperar a que termine el segundo proceso
    p3.join()  # Esperar a que termine el segundo proceso

    print('Procesos finalizados.')
