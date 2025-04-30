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

Estado da matriz após 1 interações:

<pre>
1 2 1 4 1 1 1 1 1 1 
2 3 2 1 1 0 1 1 1 1 
1 2 1 1 1 1 1 0 4 1 
1 1 1 0 1 0 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 
1 1 0 1 1 0 1 1 1 1 
4 1 1 1 1 1 4 1 1 1 
1 1 1 1 1 1 1 1 1 1 
1 1 1 1 0 1 1 1 1 1 
1 1 4 1 1 1 1 1 1 1 
</pre>

<p>O conteúdo do arquivo é atualizado a cada nova iteração da simulação.</p>

---

<h2 align="center">🧩 Estrutura do Código e Lógica de Implementação</h2>

<p align="center">O projeto é dividido em três componentes principais: <strong>Matriz</strong>, <strong>Animal</strong> e <strong>Incêndio</strong>. Cada um encapsula uma parte da simulação, promovendo modularidade e clareza.</p>

---

<h3>📌 1. Classe <code>Matriz</code></h3>

<p>Responsável por armazenar, carregar e atualizar os dados da floresta representada em uma matriz 2D.</p>

<ul>
  <li><code>carregarArquivo()</code>: Lê o arquivo <code>input.dat</code> contendo dimensões e valores da matriz.</li>
  <li><code>salvarEstado()</code>: Salva o estado da matriz no arquivo <code>output.dat</code> ao final de cada iteração.</li>
  <li><code>imprimir()</code>: Exibe a matriz no terminal para visualização passo a passo.</li>
  <li><code>getDados()</code> e <code>setDados()</code>: Getters e setters para acesso controlado à matriz.</li>
</ul>

---

<h3>🐾 2. Classe <code>Animal</code></h3>

<p>Controla o comportamento do animal na floresta. Implementa sua estratégia de movimentação e lógica de sobrevivência.</p>

<ul>
  <li><code>mover(Matriz&)</code>: Tenta mover o animal para a melhor posição ortogonal possível (água > seguro > queimada). Se encontrar água, atualiza a célula e adjacentes.</li>
  <li><code>melhorPosicao()</code>: Avalia células ortogonais e retorna a de maior prioridade.</li>
  <li><code>podeMover()</code>: Verifica se o animal pode se mover para uma célula específica.</li>
  <li><code>estaSeguro()</code>: Retorna se o animal ainda pode ficar parado sem ser considerado cercado.</li>
  <li><code>getPosicao()</code> e <code>getPassosPercorridos()</code>: Getters para registrar informações da simulação.</li>
</ul>

<p><strong>Estados monitorados:</strong> passos percorridos, iterações sem se mover, número de encontros com água.</p>

---

<h3>🔥 3. Classe <code>Incendio</code></h3>

<p>Gerencia a propagação do fogo a cada iteração. O fogo se propaga de forma ortogonal e pode ser influenciado pelo vento, se ativado no <code>config.hpp</code>.</p>

<ul>
  <li><code>executarIteracao()</code>: Atualiza a matriz com base no estado atual do fogo, propagando as chamas.</li>
  <li><code>atualizarCelula(x, y)</code>: Aplica a lógica de transição da célula (1→2, 2→3).</li>
  <li><code>existeVizinhoEmChamas(x, y)</code>: Verifica se uma célula saudável deve entrar em chamas, levando em conta o vento.</li>
  <li><code>temFogo()</code>: Verifica se ainda há células em chamas (condição para continuar a simulação).</li>
</ul>

---

<h3>🚀 4. Função <code>main()</code></h3>

<p>Orquestra a simulação, seguindo o seguinte fluxo:</p>

<ol>
  <li>Carrega a matriz do arquivo <code>input.dat</code></li>
  <li>Cria os objetos <code>Animal</code> e <code>Incendio</code></li>
  <li>Executa até <code>numInt</code> interações ou até o incêndio acabar</li>
  <li>Em cada iteração:
    <ul>
      <li>O animal se move</li>
      <li>Verifica se ele está seguro</li>
      <li>O fogo se propaga</li>
      <li>A matriz é salva e impressa</li>
      <li>Se não houver mais fogo, a simulação termina</li>
    </ul>
  </li>
  <li>Ao final, exibe no terminal os resultados do animal (posição, passos, etc.)</li>
</ol>

---

<h3>🧾 5. Arquivo de Configuração <code>config.hpp</code></h3>

<p>Permite configurar globalmente a simulação:</p>

<ul>
  <li><code>numInt</code>: Número máximo de interações</li>
  <li><code>influenciaVento</code>: Ativa ou desativa a influência do vento</li>
  <li><code>direcaoVento</code>: Vetor indicando as direções permitidas para propagação do fogo</li>
</ul>

<p>As direções seguem o seguinte índice: <code>0 = cima</code>, <code>1 = baixo</code>, <code>2 = esquerda</code>, <code>3 = direita</code>.</p>

---

<h2 align="center">👨‍💻 Autor</h2>

<p align="center"><strong>Nome:</strong> Humberto</p>
<p align="center"><strong>Curso:</strong> Engenharia da Computação - CEFET-MG</p>
