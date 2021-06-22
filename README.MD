![Logo of the project](https://www.huffmancoding.com/wp-content/uploads/2008/12/dah.jpg)

# Codificação de Huffman:
> David Albert Huffman (9 de agosto de 1925 — Santa Cruz, 7 de outubro de 1999) foi um pioneiro no campo da ciência da computação.

Este método de compressão é um dos mais utilizados na atualidade para compressão de diversos tipos de mídias diferentes – na maioria das vezes, como componente de codecs mais complexos (Salomon, 2007) – apesar de ter sido inicialmente desenvolvido para compressão de texto (Pu, 2006).

David Huffman, que desenvolveu o método como projeto da disciplina de "Teoria da Informação" em 1950 (Blelloch, 2001), enquanto era aluno de Doutoramento no MIT (Sayood, 2006) (Wikimedia Foundation, Inc., 2016), e publicou as suas conclusões em 1952 no artigo “A Method for the Construction of Minimum-Redundancy Codes” na revista Proceedings of the I.R.E. (Huffman, 1952).

A codificação de Huffman é baseada na "Teoria de Informação" de Shannon (Shannon, 1948), onde em um elemento de informação (texto, imagem, áudio, etc.) representado por símbolos, alguns desses símbolos ocorrem mais vezes que outros. Se representarmos esses símbolos mais comuns utilizando códigos menores (usando menos bits), por exemplo; iremos obter uma codificação binária com menos bits, como resultado de uma diminuição do comprimento médio (em bits) de cada código (Huffman, 1952) (Pu, 2006). O algoritmo de Huffman é, portanto, baseado na categoria de Codificação de Entropia – a informação é encarada como uma sequência de símbolos genéricos, menosprezando a semântica dos mesmos -, sendo um modo de codificação sem perdas – o código resultante é totalmente reversível; ou seja, a sua decodificação resulta num fluxo de dados exactamente igual ao fluxo de dados de origem (Ribeiro, Apontamentos das Aulas, 2016).

## Pré-Requisitos:
- [Ambiente linux](https://www.linux.org/pages/download/)
- [Compilador GCC](https://gcc.gnu.org/install/index.html)
- [Makefile](https://www.unixmen.com/install-ubuntu-make-on-ubuntu-15-04/)

Também pode ser executado em um ambiente Windows, desde que se tenha uma versão do gcc instalado. Neste caso, o MakeFile não funcionará, e um arquivo .bat deverá ser criado.

IDE's também podem executar esta aplicação sem nenhum problema. Tais como:
- [Code:Blocks] (https://www.codeblocks.org/)
- [DevC++] (https://sourceforge.net/projects/orwelldevcpp/)
- [Visual Studio Code](https://code.visualstudio.com/)

- Esta aplicação foi desenvolvida e testada em um ambiente Linux Ubuntu, com testes também realizados em ambiente Windows com a IDE CodeBlocks.

## Instalação:

Nenhuma instalação adicional é requerida. Apenas os prés-requisitos citados acima.

A única configuração utilizada, foi o Makefile para simplificar o processo de compilação.

### Gerando o Arquivo Binário:

- Execute o comando a seguir, para gerar o arquivo binário:
```shell
$~ Makefile
```

### Executando a Aplicação:

- Caso o comando Makefile tenha funcionado corretamente, aplicação poderá ser executada da seguinte maneira:
```shell
$~ ./nome_da_aplicacao [Parâmetro 1] [Parâmetro 2] [Parâmetro 3]
```
Onde - Compressão:
- Parâmetro 1 = "-c" Comprime o Arquivo
- Parâmetro 2 = Nome do Arquivo a Ser Comprimido (entrada)
- Parâmetro 3 = Nome do Arquivo a Ser Gerado (saída)

Onde - Descompressão:
- Parâmetro 1 = "-d" Descomprime o Arquivo
- Parâmetro 2 = Nome do Arquivo a Ser Descomprimido (entrada)
- Parâmetro 3 = Nome do Arquivo a Ser Gerado (saída)

Exemplo:
```shell
$~ ./huffman -c comprima.isso nisso.hx
```

NOTA: Por padrão, o arquivo compactado terá a extensão ".hx"

## Features:

What's all the bells and whistles this project can perform?
* What's the main functionality
* You can also do another thing
* If you get really randy, you can even do this

## Configuration:

Here you should write what are all of the configurations a user can enter when
using the project.

#### Argument 1:
Type: `String`  
Default: `'default value'`

State what an argument does and how you can use it. If needed, you can provide
an example below.

Example:
```bash
awesome-project "Some other value"  # Prints "You're nailing this readme!"
```

#### Argument 2:
Type: `Number|Boolean`  
Default: 100

Copy-paste as many of these as you need.

## Contributing:

When you publish something open source, one of the greatest motivations is that
anyone can just jump in and start contributing to your project.

These paragraphs are meant to welcome those kind souls to feel that they are
needed. You should state something like:

"If you'd like to contribute, please fork the repository and use a feature
branch. Pull requests are warmly welcome."

If there's anything else the developer needs to know (e.g. the code style
guide), you should link it here. If there's a lot of things to take into
consideration, it is common to separate this section to its own file called
`CONTRIBUTING.md` (or similar). If so, you should say that it exists here.

## Links:

Even though this information can be found inside the project on machine-readable
format like in a .json file, it's good to include a summary of most useful
links to humans using your project. You can include links like:

- Project homepage: https://your.github.com/awesome-project/
- Repository: https://github.com/your/awesome-project/
- Issue tracker: https://github.com/your/awesome-project/issues
  - In case of sensitive bugs like security vulnerabilities, please contact
    my@email.com directly instead of using issue tracker. We value your effort
    to improve the security and privacy of this project!
- Related projects:
  - Your other project: https://github.com/your/other-project/
  - Someone else's project: https://github.com/someones/awesome-project/


## Licensing:

One really important part: Give your project a proper license. Here you should
state what the license is and how to find the text version of the license.
Something like:

"The code in this project is licensed under MIT license."

## Referências:
- Salomon, D. (2007). Data Compression (4th ed.). London: Springer.
- Pu, I. M. (2006). Fundamental Data Compression. Oxford, United Kingdom: Elsevier.
- Blelloch, G. E. (2001). Introduction to Data Compression. In G. E. Blelloch, Algorithms in the Real World. Pittsburg, PA, United States of America: Carnegie Mellon University.
- Sayood, K. (2006). Introduction to Data Compression. San Francisco: Morgan Kauffman.
- Wikimedia Foundation, Inc. (30/03/2016). Huffman Coding. Acessado em 21/06/2021, de Wikipedia, the free encyclopedia: https://en.wikipedia.org/wiki/Huffman_coding
- Huffman, D. A. (1952). A Method for the Construction of Minimum-Redundancy Codes. Proceedings of the I.R.E., 1098-1101.
- Shannon, C. E. (1948). A Mathematical Theory of Communication. Bell System Technical Journal, 27, 379–423 & 623–656.
- Ribeiro, N. (2016). Apontamentos das Aulas. Multimédia II. Porto: Universidade Fernando Pessoa.
