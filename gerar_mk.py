import os
from sys import prefix
import json

FLAGS="-Lraylib/raylib-linux/lib -Wl,-Bstatic -lraylib -Wl,-Bdynamic -lm -lpthread -ldl -lrt -lX11 -flto -fsanitize=address -Wall"
INCLUDES="-Iincludes -Iraylib/raylib-linux/include -Iraylib/raygui/src"
SRC_FOLDER="src"
INCLUDE_FOLDER="includes"
SAIDA="go_and_conquer.elf"
NOME_MKF="makefile"

def scan_folder_rec(lista, pasta,  objetivo):
    for coisa in os.listdir(pasta):
        if os.path.isdir(f"{pasta}/{coisa}"):
            scan_folder_rec(lista, f"{pasta}/{coisa}", objetivo)
        elif coisa.lower().endswith(objetivo):
            lista.append({
                'nome': coisa.removesuffix(objetivo),
                'caminho': f"{pasta}/{coisa}"
            })

def ha_em_ambos(lista, item):
    for item_lista in lista:
        if item_lista.get("nome") == item:
            return item_lista.get("caminho")

    return ""

lista_arqs_c = []
scan_folder_rec(lista_arqs_c, SRC_FOLDER, ".c")
print("Arquivos .C: \n" + json.dumps(lista_arqs_c, ensure_ascii=False, indent=4))

lista_arqs_h = []
scan_folder_rec(lista_arqs_h, INCLUDE_FOLDER, ".h")
print("\nArquivos .H: \n" + json.dumps(lista_arqs_h, ensure_ascii=False, indent=4))

with open(NOME_MKF, "w") as f:
    arqs_o=""
    for arq in lista_arqs_c:
        arqs_o += f"build/{arq.get("nome")}.o "

    f.write(f"INCLUDES:={INCLUDES}\n")
    f.write(f"FLAGS:={FLAGS}\n")
    f.write(f"CODIGO_O:={arqs_o}\n\n")

    f.write(f"""
{SAIDA}: build/ $(CODIGO_O)
\tgcc -o {SAIDA} $(CODIGO_O) $(INCLUDES) $(FLAGS)
""")

    for arq in lista_arqs_c:
        f.write(f"""
build/{arq.get("nome")}.o: {arq.get("caminho")} {ha_em_ambos(lista_arqs_h, arq.get("nome"))}
\tgcc -c {arq.get("caminho")} $(INCLUDES) $(FLAGS) -o build/{arq.get("nome")}.o
""")

    f.write(f"""
build/:
\tmkdir build/

clear:
\trm {SAIDA}; rm -r build/
""")
