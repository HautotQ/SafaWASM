#include <emscripten.h>
#include <stdio.h>

// Déclaration JS pour mettre à jour le canvas
EM_JS(void, update_canvas, (int value), {
    const canvas = document.getElementById('myCanvas');
    const ctx = canvas.getContext('2d');
    ctx.clearRect(0, 0, canvas.width, canvas.height);
    ctx.font = '30px Arial';
    ctx.fillStyle = 'blue';
    ctx.fillText('Compteur: ' + value, 50, 50);
});

int counter = 0;

// Fonction appelée depuis JS
void increment_counter() {
    counter++;
    update_canvas(counter);
}

int main() {
    printf("WebAssembly prêt !\n");
    // Initialise l'affichage
    update_canvas(counter);
    return 0;
}
