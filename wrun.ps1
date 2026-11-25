    echo "Tentanto Compilar"

    $diretorioLocal = $PSScriptRoot

    echo $diretorioLocal

    cd 'C:\Users\filipe.schausst_unes\Documents\compilador\bin'

    .\gcc.exe -I"$diretorioLocal\includes" -I"$diretorioLocal/raylib/raylib-win/include" -I"$diretorioLocal/raylib/raygui/src" $diretorioLocal\src\*.c $diretorioLocal\src\telas\*.c $diretorioLocal\src\helpers\*.c -L"$diretorioLocal/raylib/raylib-win/lib" -lraylib -lgdi32 -lwinmm -o $diretorioLocal\game.exe #-Wall

    cd $diretorioLocal

    echo "Fim Compilação"