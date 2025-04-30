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

<h2 align="center">📁 Estrutura do Projeto</h2>

<p align="center">O projeto está organizado em pastas de forma modular, separando as responsabilidades por diretório:</p>

<ul>
  <li><strong>include/</strong>: Arquivos de cabeçalho (.hpp), contendo as declarações das classes</li>
  <li><strong>src/</strong>: Implementações em C++ (.cpp)</li>
  <li><strong>build/</strong>: Arquivos de build gerados automaticamente</li>
  <li><strong>input.dat</strong>: Matriz de entrada da floresta</li>
  <li><strong>output.dat</strong>: Estado da matriz após cada iteração</li>
  <li><strong>Makefile</strong>: Automatizador de compilação e execução</li>
</ul>

---

<h2 align="center">⚙️ Compilação e Execução</h2>

<p align="center">Todos os comandos devem ser executados no terminal Linux dentro da pasta raiz do projeto.</p>

<ul>
  <li><code>make clean</code> – Remove todos os arquivos de build anteriores</li>
  <li><code>make</code> – Compila os arquivos e gera o executável</li>
  <li><code>make run</code> – Executa a simulação</li>
</ul>

---

<h2 align="center">📌 Regras da Simulação</h2>

<table align="center">
  <tr><th>Valor</th><th>Significado</th></tr>
  <tr><td>0</td><td>Área vazia</td></tr>
  <tr><td>1</td><td>Árvore saudável</td></tr>
  <tr><td>2</td><td>Árvore em chamas</td></tr>
  <tr><td>3</td><td>Árvore queimada</td></tr>
  <tr><td>4</td><td>Fonte de água</td></tr>
</table>

<ul>
  <li>🌲 Árvore saudável entra em chamas se houver vizinho em chamas (ortogonal)</li>
  <li>🔥 Árvore em chamas vira árvore queimada na próxima iteração</li>
  <li>🌬️ Propagação pode ser influenciada por vento (se ativado no <code>config.hpp</code>)</li>
  <li>🚶‍♂️ O animal se move antes da propagação do fogo</li>
  <li>💧 Ao encontrar água, a célula vira 0 e vizinhos viram 1</li>
</ul>

---

<h2 align="center">🐾 Estratégia de Fuga do Animal</h2>

<ul>
  <li>🔹 Movimenta-se ortogonalmente buscando a melhor posição</li>
  <li>🔹 Prioridade: água (4) > área segura (0/1) > queimada (3)</li>
  <li>🔹 Permanece em célula segura (0) por até 3 interações</li>
  <li>🔹 Se não puder se mover, a simulação é encerrada com o animal cercado</li>
</ul>

---

<h2 align="center">📤 Exemplo de Entrada</h2>

<p><code>input.dat</code>:</p>

<pre>
10 10 1 1
1 1 1 4 1 1 1 1 1 1
1 2 1 1 1 0 1 1 1 1
1 1 1 1 1 1 1 0 4 1
1 1 1 0 1 0 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 0 1 1 0 1 1 1 1
4 1 1 1 1 1 4 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 0 1 1 1 1 1
1 1 4 1 1 1 1 1 1 1
</pre>

---

<h2 align="center">📈 Exemplo de Saída</h2>

<p><code>output.dat</code>:</p>

<pre>
Iteração 1:
1 2 1 4 1 1 ...
2 2 2 1 1 0 ...
...
</pre>

<p>O conteúdo do arquivo é atualizado a cada nova iteração da simulação.</p>

---

<h2 align="center">📊 Resultados Monitorados</h2>

<ul>
  <li>✔️ Total de passos percorridos pelo animal</li>
  <li>✔️ Número de encontros com água</li>
  <li>✔️ Iteração final (quando o fogo apaga ou o animal é cercado)</li>
</ul>

---

<h2 align="center">💡 Possíveis Melhorias</h2>

<ul>
  <li>🔸 Implementar algoritmos de fuga otimizados (A*, Dijkstra)</li>
  <li>🔸 Suporte a múltiplos animais</li>
  <li>🔸 Simulação visual com interface gráfica (SFML, OpenGL)</li>
  <li>🔸 Exportação de dados analíticos (tempo por iteração, áreas queimadas, etc.)</li>
</ul>

---

<h2 align="center">👨‍💻 Autor</h2>

<p align="center"><strong>Nome:</strong> Humberto</p>
<p align="center"><strong>Curso:</strong> Engenharia da Computação - CEFET-MG</p>
<p align="center"><strong>Data de Entrega:</strong> 20 de abril de 2025</p>
