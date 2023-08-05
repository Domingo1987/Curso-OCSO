import threading
import subprocess
import time


def ejecutarComando(comando):
    # Ejecuta el comando en la terminal
    #subprocess.run(comando, shell=True)
    subprocess.call(comando, shell=True)
    time.sleep(3)  # Simula un trabajo que tarda 2 segundos


if __name__ == "__main__":
    # Definir los comandos que se van a ejecutar
    comando1 = "ls -lr /"
    comando2 = "ls -lr /usr"

    # Crear dos hilos, cada uno para ejecutar un comando
    hilo1 = threading.Thread(target=ejecutarComando, args=(comando1,))
    hilo2 = threading.Thread(target=ejecutarComando, args=(comando2,))

    print('Iniciando hilos...')
    hilo1.start()  # Iniciar el primer hilo
    hilo2.start()  # Iniciar el segundo hilo

    print('Esperando a que los hilos terminen...')
    hilo1.join()  # Esperar a que termine el primer hilo
    hilo2.join()  # Esperar a que termine el segundo hilo

    print('Hilos finalizados.')