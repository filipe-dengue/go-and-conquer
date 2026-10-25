import os

caminho = "raylib/raygui/styles"

lista = []

for item in os.listdir("raylib/raygui/styles"):
    caminho_completo = os.path.join(caminho, item)
    if os.path.isdir(caminho_completo):
        lista.append(item)

string = ""
for coisa in lista:

    string += f"\"{coisa}\",\n"

print(string)
