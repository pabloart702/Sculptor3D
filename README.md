# Sculptor 3D

Uma ferramenta em C++ para modelagem geométrica 3D baseada em voxels.

O **Sculptor 3D** permite a criação de esculturas digitais através da manipulação de uma matriz de voxels (pixels tridimensionais), semelhante à mecânica de construção de jogos como *Minecraft*. O resultado final é exportado para o formato **.OFF** (Object File Format), que pode ser visualizado em softwares de modelagem 3D.

![Exemplo da Escultura](https://github.com/pabloart702/Sculptor3D/assets/112511278/457dfc70-9702-4c02-9b69-f35ea4543f45)

## Funcionalidades

A classe `Sculptor` oferece métodos para manipular a matriz 3D, permitindo adicionar ou remover formas geométricas com cores e transparências específicas.

### Primitivas Suportadas:
- **Voxels:** Adicionar/Remover um único voxel.
- **Caixas (Box):** Adicionar/Remover regiões retangulares (paralelepípedos).
- **Esferas:** Adicionar/Remover esferas baseadas em um raio e centro.

### Atributos Visuais:
- **Cores:** Definição de cores RGB (Vermelho, Verde, Azul).
- **Transparência:** Controle do canal Alpha (opacidade).

### Saída:
- Geração de arquivos `.off` contendo a malha geométrica (vértices e faces) pronta para visualização.

## Como Funciona (Implementação Técnica)

O projeto é estruturado em três arquivos principais:

1.  **`sculptor.h`**: Define a estrutura `Voxel` e a classe `Sculptor`.
2.  **`sculptor.cpp`**: Implementa a lógica de manipulação da matriz 3D.
    - Utiliza alocação dinâmica de memória para criar uma matriz tridimensional (`Voxel ***v`).
    - Realiza cálculos matemáticos para determinar se um voxel pertence a uma esfera ($x^2 + y^2 + z^2 \le r^2$).
    - O método `writeOFF` percorre a matriz e escreve apenas os voxels ativos (`show = true`) no arquivo de saída, calculando os 8 vértices de cada cubo.
3.  **`main.cpp`**: Exemplo de uso que gera uma escultura complexa (uma torre com detalhes e uma lua).

## Compilação e Execução

Para compilar o projeto, você precisará de um compilador C++ (como `g++`).

### Passos:

1.  **Clone o repositório:**
    ```bash
    git clone [https://github.com/seu-usuario/Sculptor3D.git](https://github.com/seu-usuario/Sculptor3D.git)
    cd Sculptor3D
    ```

2.  **Compile o código:**
    ```bash
    g++ main.cpp sculptor.cpp -o escultor
    ```

3.  **Execute o programa:**
    - No Linux/Mac:
      ```bash
      ./escultor
      ```
    - No Windows:
      ```bash
      escultor.exe
      ```

## Como Visualizar

O programa gera um arquivo `.off` (ex: `torre.off`). Para visualizar sua escultura, utilize um software compatível, como:

* **MeshLab**
* **Geomview**

Basta abrir o arquivo gerado no software para rotacionar, ampliar e inspecionar sua criação 3D.

## Exemplo de Uso

Abaixo, um exemplo simples de como instanciar a classe e desenhar formas:

```cpp
#include "sculptor.h"

int main() {
    // 1. Instancia um escultor de 10x10x10 voxels
    Sculptor sc(10, 10, 10);

    // 2. Define a cor (Vermelho)
    sc.setColor(1.0, 0.0, 0.0, 1.0);

    // 3. Cria uma caixa no centro
    sc.putBox(2, 7, 2, 7, 2, 7);

    // 4. Remove o miolo (furo passante)
    sc.cutBox(4, 5, 4, 5, 0, 9);

    // 5. Salva o arquivo
    sc.writeOFF("exemplo.off");

    return 0;
}
