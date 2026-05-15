/
        section {
            margin-bottom: 20px;
        }

        
        main > div:last-of-type {
            margin-top: 32px;
        }

        
        footer p {
            font-size: 0.85rem;
            color: #5c6f87;
            margin: 0;
            text-align: center;
        }

        
        .video-group {
            margin-bottom: 20px;
        }

        
        @media (max-width: 650px) {
            body {
                padding: 16px;
            }
            header, main, footer {
                padding: 18px 20px;
            }
            h1 {
                font-size: 1.7rem;
            }
            h2 {
                font-size: 1.45rem;
            }
            .video-item {
                flex-direction: column;
                align-items: flex-start;
                gap: 6px;
            }
            h4 {
                margin-left: 0;
            }
        }
    </style>
</head>
<body>

<header>
    <h1>Олимп. про</h1>
    <p>Дополнительные материалы к Telegram-боту</p>
</header>

<main>
    <section>
        <h2>Видеоуроки по программированию</h2>
        <p>Подборка материалов по Python и C++ для подготовки к олимпиадам</p>
    </section>

    <!-- Python блок -->
    <section>
        <h2>Python</h2>

        <div>
            <h3>Основы Python</h3>
            <div class="video-item">
                <a href="https://youtu.be/h1IqgaZBi-8?si=3glIR5orbdGjDgYW" target="_blank">
                    Установка Python и настройка среды
                </a>
                <h4>(-- мин)</h4>
            </div>
            <div class="video-item">
                <a href="https://youtu.be/DZvNZ9l9NT4?si=lm5i_jdfQdkUCPVD" target="_blank">
                    Переменные, типы данных и операции
                </a>
                <h4>(-- мин)</h4>
            </div>
            <div class="video-item">
                <a href="https://youtu.be/vMD6-jzgDvI?si=t_sJXFkWFI_IxoRh" target="_blank">
                    Условные операторы и циклы
                </a>
                <h4>(-- мин)</h4>
            </div>
        </div>

        <div>
            <h3>Олимпиадные задачи</h3>
            <div class="video-item">
                <a href="https://youtu.be/qwgjFDbInao?si=5tV4doMku-2ZGp7G" target="_blank">
                    Сортировки и бинарный поиск в задачах
                </a>
                <h4>(-- мин)</h4>
            </div>
            <div class="video-item">
                <a href="https://youtu.be/SuwL6BYIfQM?si=lm_4KwS8Nz7XZfg5" target="_blank">
                    Динамическое программирование
                </a>
                <h4>(-- мин)</h4>
            </div>
            <div class="video-item">
                <a href="https://youtu.be/B21nJhU4x3A?si=WPnPE_E1M242hE96" target="_blank">
                    Обход графов (DFS и BFS) на Python
                </a>
                <h4>(-- мин)</h4>
            </div>
        </div>
    </section>

    <!-- Блок C++ (без отдельного section, чтобы не менять структуру) -->
    <div>
        <h3>Олимпиадный C++</h3>
        <div class="video-item">
            <a href="https://www.youtube.com/watch?v=dQw4w9WgXcQ" target="_blank">
                STL: vector, set, map для олимпиад
            </a>
            <h4>(-- мин)</h4>
        </div>
        <div class="video-item">
            <a href="https://www.youtube.com/watch?v=dQw4w9WgXcQ" target="_blank">
                Динамическое программирование в C++
            </a>
            <h4>(-- мин)</h4>
        </div>
        <div class="video-item">
            <a href="https://www.youtube.com/watch?v=dQw4w9WgXcQ" target="_blank">
                Алгоритмы на графах и оптимизация
            </a>
            <h4>(-- мин)</h4>
        </div>
    </div>
</main>
<footer>
    <p> Олимп. про</p>
</footer>

</body>
</html>
```