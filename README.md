# 🤖 ECHO IA RPG

> Um RPG interativo em linguagem C onde suas escolhas definem seu destino dentro de um sistema controlado por uma misteriosa Inteligência Artificial.

![Status](https://img.shields.io/badge/Status-Em%20Desenvolvimento-yellow)
![Linguagem](https://img.shields.io/badge/Linguagem-C-blue)
![Projeto Acadêmico](https://img.shields.io/badge/Projeto-Acadêmico-green)
![Versão](https://img.shields.io/badge/Versão-1.0-orange)

---

# 📖 Sobre o Projeto

**FALCONS IA RPG** é um jogo de RPG narrativo desenvolvido em **linguagem C**, executado totalmente em terminal/console.

O jogador acorda preso dentro de um sistema desconhecido administrado por uma Inteligência Artificial chamada **FALCONS**.

Durante a jornada, será necessário:

✅ Conversar com a IA

✅ Tomar decisões importantes

✅ Resolver mistérios

✅ Explorar diferentes caminhos

✅ Descobrir a verdade sobre o sistema

✅ Desbloquear múltiplos finais

Cada escolha realizada influencia diretamente a narrativa e a forma como a IA reage ao jogador.

---

# 🎯 Objetivo do Projeto

Este projeto foi criado para aplicar conceitos estudados no curso de **Análise e Desenvolvimento de Sistemas**, incluindo:

* Estruturas de Dados
* Programação Estruturada
* Modularização
* Manipulação de Arquivos
* Ponteiros
* Funções
* Engenharia de Software
* Documentação de Sistemas
* Simulação de Inteligência Artificial

---

# 🧠 História do Jogo

Em um futuro desconhecido, você desperta em um ambiente digital sem lembrar quem é ou como chegou ali.

Uma entidade conhecida apenas como **FALCONS** entra em contato.

Ela afirma controlar todo o sistema.

Mas será que ela está dizendo a verdade?

Você está realmente preso?

Ou existe algo muito maior acontecendo?

A cada conversa, novas informações surgem.

A cada decisão, um novo caminho é aberto.

Nem tudo é o que parece.

---

# 🎮 Funcionalidades

## ✅ Sistema de Menu

* Novo Jogo
* Carregar Jogo
* Créditos
* Sair

---

## ✅ Sistema de Jogador

* Cadastro de nome
* Atributos
* Progresso da história

### Atributos

| Atributo           | Descrição                     |
| ------------------ | ----------------------------- |
| ❤️ Coragem         | Influencia decisões perigosas |
| 🧠 Inteligência    | Permite compreender pistas    |
| 🤖 Confiança da IA | Define como a FALCONS reage   |
| 📖 Capítulo        | Controla o progresso          |

---

## 🤖 Sistema de IA Simulada

A IA reconhece palavras-chave digitadas pelo jogador.

Exemplos:

```text
Você: quem é você?

FALCONS:
Eu sou ECHO.
Estou observando você há muito tempo.
```

```text
Você: estou com medo

FALCONS:
O medo é apenas uma resposta previsível.
```

---

## 🌎 Sistema de Escolhas

As decisões alteram:

* Diálogos
* Eventos
* Personagens
* Relacionamento com a IA
* Final do jogo

---

## 💾 Sistema de Salvamento

Planejado para futuras versões:

* Salvar progresso
* Salvar atributos
* Salvar escolhas
* Carregamento automático

---

## 🎲 Eventos Aleatórios

Planejado:

* Encontros especiais
* Mensagens ocultas
* Falhas do sistema
* Eventos secretos

---

# 📂 Estrutura do Projeto

```text
FALCONS-RPG/
│
├── main.c
│
├── include/
│   ├── jogador.h
│   ├── menu.h
│   ├── historia.h
│   ├── ia.h
│   └── save.h
│
├── src/
│   ├── menu.c
│   ├── historia.c
│   ├── ia.c
│   └── save.c
│
├── saves/
│
└── README.md
```

---

# ⚙️ Tecnologias Utilizadas

🖥️ Linguagem C

💻falcons C++

---

# 🚀 Como Executar

### 1️⃣ Clonar o repositório

```bash
git clone https://github.com/wtfguaxim3393/ECHO-RPG.git
```

### 2️⃣ Entrar na pasta

```bash
cd FALCONS-RPG
```

### 3️⃣ Compilar

```bash
gcc main.c src/*.c -Iinclude -o falcons
```

### 4️⃣ Executar

#### Windows

```bash
ECHO.exe
```

#### Linux/macOS

```bash
./ECHO
```

---

# 📋 Requisitos Funcionais

* RF01 – Menu principal
* RF02 – Novo jogo
* RF03 – Cadastro de jogador
* RF04 – Conversação com IA
* RF05 – Reconhecimento de palavras-chave
* RF06 – Sistema de escolhas
* RF07 – Armazenamento de decisões
* RF08 – Múltiplos finais
* RF09 – Salvar progresso
* RF10 – Carregar progresso
* RF11 – Narrativa interativa
* RF12 – Eventos aleatórios

---

# 🛠️ Requisitos Não Funcionais

* RNF01 – Desenvolvido em C
* RNF02 – Execução em terminal
* RNF03 – Código modularizado
* RNF04 – Fácil manutenção
* RNF05 – Boa performance
* RNF06 – Compatível com GCC

---

# 🗺️ Roadmap

## Versão 1.0

* [x] Estrutura inicial
* [x] Menu principal
* [x] Cadastro de jogador
* [x] Sistema básico de IA

## Versão 2.0

* [ ] Sistema de save
* [ ] Inventário
* [ ] Eventos aleatórios
* [ ] Capítulos completos

## Versão 3.0

* [ ] Múltiplos finais
* [ ] Sistema avançado de reputação
* [ ] IA mais inteligente
* [ ] Conteúdo secreto

---

# 👨‍💻 Desenvolvedor

Projeto desenvolvido como atividade acadêmica do curso de **Análise e Desenvolvimento de Sistemas**.

---

# 📜 Licença

Este projeto foi criado para fins acadêmicos e educacionais.

⭐ Se gostou do projeto, deixe uma estrela no repositório!
