<h1 align="center">🔥 Simulador de Propagação de Incêndios 🔥</h1>

<h2 align="center">Trabalho Prático de Estruturas de Dados em C++</h2>

<p align="center">
  <img src="https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white" alt="C++ Badge">
</p>

---

<h2 align="center">📘 Introdução</h2>

<p align="center">Este projeto foi desenvolvido como parte do trabalho prático da disciplina de Estruturas de Dados, ministrada no CEFET-MG. O objetivo é simular, de forma visual e interativa, a propagação de um incêndio em uma floresta representada por uma matriz, considerando regras de propagação, influência do vento e estratégias de fuga de um animal presente no ambiente.</p>

---

<h3 align="center">🎯 Objetivos da Simulação</h3>

<ul>
  <li> Modelar a propagação do fogo em uma matriz com base em regras pré-definidas</li>
  <li> Implementar estratégias de movimentação inteligente de um animal</li>
  <li> Avaliar o comportamento do sistema com e sem a influência do vento</li>
  <li> Registrar o histórico da matriz em arquivo de saída e os dados do animal</li>
</ul>

---

<h2 align="center">📁 Estrutura do Projeto</h2>

TrabalhoAquecimento/ ├── build/ # Diretório de saída (binários, objetos) ├── include/ # Arquivos de cabeçalho (.hpp) │ ├── animal.hpp │ ├── incendio.hpp │ ├── matriz.hpp │ └── config.hpp ├── src/ # Implementações das classes (.cpp) │ ├── animal.cpp │ ├── incendio.cpp │ ├── matriz.cpp │ └── main.cpp ├── input.dat # Arquivo de entrada com a matriz inicial ├── output.dat # Arquivo gerado com os estados da matriz a cada iteração ├── Makefile # Arquivo de automação da compilação └── README.md # Documentação explicativa
