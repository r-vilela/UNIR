<header>
    <h2>Entre em contato</h2>
</header>
<main>
    <section id="form-contato">
<?php
    $status = "";
    if($_SERVER["REQUEST_METHOD"] == "POST") {
        $nome = htmlspecialchars($_POST['nome']);
        $mensagem = htmlspecialchars($_POST['mensagem']);
        $email = htmlspecialchars($_POST['email']);
        $status = "Obrigado, $nome!\n A mensagem '$mensagem' foi recebida com sucesso.\nEntraremos em contato pelo email $email.";
    }
?>
        <form method="post">

            <label for="nome">Nome:</label><br>
            <input type="text" id="nome" name="nome" required><br><br>

            <label for="email">Email:</label><br>
            <input type="email" id="email" name="email" required><br><br>

            <label for="mensagem">Mensagem:</label><br>
            <textarea id="mensagem" name="mensagem" rows="4" cols="30"></textarea><br><br>

            <button type="submit">Enviar</button>

        </form>
        <p><?php echo nl2br($status); ?></p>
    </section>
</main>
