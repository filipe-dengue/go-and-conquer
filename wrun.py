import os
import subprocess

ENDERECO_COMPILADOR = "C:\\Program Files\\CodeBlocks\\MinGW\\bin"
ENDERECO_ATUAL = os.getcwd # Terminar isso depois, conseguir pasta atual

FLAGS="-Llib -lraylib -lgdi32 -lwinmm -Wall"
INCLUDES="-Iincludes -Iraylib\\raylib-linux\\include" #-Iraylib\\raygui\\src"
SRC_FOLDER="src"
SAIDA="go_and_conquer.exe"

def scan_folder_rec(lista, pasta,  objetivo):
    for coisa in os.listdir(pasta):
        if os.path.isdir(f"{pasta}/{coisa}"):
            scan_folder_rec(lista, f"{pasta}\\{coisa}", objetivo)
        elif coisa.lower().endswith(objetivo):
            lista.append({
                'nome': coisa.removesuffix(objetivo),
                'caminho': f"{pasta}\\{coisa}"
            })

def lista_to_string(lista):
    s = ""
    for item in lista:
        s += item.get("caminho", "") + " "

    return s

lista_arqs_c = []
scan_folder_rec(lista_arqs_c, SRC_FOLDER, ".c")

str_arqs_c = lista_to_string(lista_arqs_c)
print(str_arqs_c)

print("powershell.exe", "-Command", ENDERECO_COMPILADOR, "-o", SAIDA, str_arqs_c, INCLUDES, FLAGS)

subprocess.run([
    "powershell.exe", "-Command", "cd", ENDERECO_COMPILADOR
])

subprocess.run([
    "powershell.exe", "-Command", "pwd"
])

subprocess.run([
    "powershell.exe", "-Command", "gcc.exe", "-o", SAIDA, str_arqs_c, INCLUDES, FLAGS
])
