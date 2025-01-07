<h2>Descrição</h2>
<p>O <strong>So Long</strong> é um projeto da 42 cujo objetivo é desenvolver um pequeno jogo em 2D utilizando a biblioteca <strong>MinilibX</strong>. O jogo tem como base uma mecânica simples: o jogador deve controlar um personagem para coletar itens, evitar inimigos (se houver) e chegar à saída de um mapa, garantindo que todas as regras e funcionalidades estejam em conformidade com as especificações exigidas.</p>

<h2>Objetivos do Projeto</h2>
<ul>
    <li>Aprender sobre renderização gráfica e gerenciamento de janelas usando a <strong>MinilibX</strong>.</li>
    <li>Trabalhar com manipulação de arquivos para carregar e validar mapas.</li>
    <li>Aplicar conceitos de gestão de memória e prevenir vazamentos.</li>
    <li>Desenvolver um jogo funcional e esteticamente atrativo em C.</li>
</ul>

<h2>Requisitos</h2>
<ul>
    <li><strong>Biblioteca MinilibX</strong>: O projeto utiliza a MinilibX para renderizar o jogo.</li>
    <li><strong>Mapas Válidos</strong>: O mapa deve ser um arquivo <code>.ber</code> contendo uma representação retangular da área do jogo. Cada mapa deve incluir:
        <ul>
            <li>Um caractere <code>P</code> para indicar a posição inicial do jogador.</li>
            <li>Pelo menos um <code>C</code> para representar os itens colecionáveis.</li>
            <li>Um caractere <code>E</code> para indicar a saída.</li>
            <li>Paredes representadas por <code>1</code> e espaços vazios por <code>0</code>.</li>
        </ul>
    </li>
    <li><strong>Eventos do Usuário</strong>: O jogo deve reagir a entradas do teclado e fechar graciosamente ao receber o comando apropriado.</li>
</ul>

<h2>Funcionalidades</h2>
<ul>
    <li><strong>Movimentação do Jogador</strong>: O jogador pode se mover nas quatro direções (cima, baixo, esquerda e direita).</li>
    <li><strong>Coleta de Itens</strong>: O jogador precisa coletar todos os itens (<code>C</code>) para abrir a saída (<code>E</code>).</li>
    <li><strong>Detecção de Colisão</strong>: O jogador não pode atravessar paredes (<code>1</code>).</li>
    <li><strong>Contagem de Movimentos</strong>: O jogo exibe o número total de movimentos feitos pelo jogador.</li>
    <li><strong>Validação do Mapa</strong>: O programa deve verificar se o mapa é válido antes de iniciar o jogo.</li>
</ul>
<h2>Compilando o Projeto</h2>
<ol>
    <li>Clone o repositório:
        <pre>
        git clone https://github.com/SEU_USUARIO/so_long.git
        cd so_long
        </pre>
    </li>
    <li>Certifique-se de que você tem a <strong>MinilibX</strong> instalada em seu sistema.</li>
    <li>Compile o projeto utilizando o <code>Makefile</code>:
        <pre>
        make
        </pre>
    </li>
    <li>Execute o jogo:
        <pre>
        ./so_long maps/mapa_exemplo.ber
        </pre>
    </li>
</ol>

<h2>Controles do Jogo</h2>
<ul>
    <li><strong>W</strong>: Mover para cima</li>
    <li><strong>A</strong>: Mover para a esquerda</li>
    <li><strong>S</strong>: Mover para baixo</li>
    <li><strong>D</strong>: Mover para a direita</li>
    <li><strong>ESC</strong>: Fechar o jogo</li>
</ul>
