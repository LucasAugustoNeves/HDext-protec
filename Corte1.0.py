# coding=utf-8
# ---------------------------------------------PYTHON-2---------------------------------------



# coding=utf-8
# -----------------------Sensor-De-Ransomware-----------------------------
# -------------IN-Scaner-Configuração----------------
from __future__ import print_function
import os  # Import the OS Module
import sys
# -------------IN-Scaner-Configuração----------------
# -------------IN-Conexão-Serial-Port-Configuração----------------
import serial
import time

porta = "COM3"
velocidade = 9600
ser = serial.Serial(porta, velocidade)
i = 0
# -------------FN-Conexão-Serial-Port-Configuração----------------
SS1 = str('C:\Safety\\''##SS1##.txt')  # colocar o caminho eo Nome do Sensor
while (i < 50): #tempo em segundos
    if os.path.exists(SS1):  # checa se diretorio exist
        print("O Diretorio Exist", SS1)
        time.sleep(1)
        i = i + 1
    else:
        # print("Nenhum Diretorio Encontrado Para " + SS1)  # Saida se nenhum diretorio
        # print()
        ser.write('1')
        time.sleep(2)
        ser.write('1')
        print("Desligado")
        i = i + 1

else:
    print("Exiting")
exit()
