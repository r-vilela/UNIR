package view;

import javax.swing.*;
import java.awt.*;
import javax.swing.border.EmptyBorder;

import model.Normal;
import model.Eletrico;
import model.Terra;
import model.PokemonModel;

import java.util.regex.*;
import java.util.ArrayList;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

import java.io.*;

public class TelaPokemon extends JFrame{

    private JPanel mainPnl;
    private JTextField txtNome;
    private JTextField txtAtaque;
    private JTextField txtDefesa;
    private JTextField txtPesquisa;
    private JTable tbl;


    public static void main(String[] args){
        EventQueue.invokeLater(new Runnable() {

            public void run() {
                try{
                    TelaPokemon frame = new TelaPokemon();
                    frame.setVisible(true);
                } catch(Exception e){
                    e.printStackTrace();
                }
            }
        });
    }

    public TelaPokemon(){
        setResizable(false);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setBounds(157, 50, 1040, 692);

		JMenuBar mnBar = new JMenuBar();
		setJMenuBar(mnBar);

		JMenu mnArquivo = new JMenu("Arquivo");
		mnBar.add(mnArquivo);

		JMenuItem mnItemAbrir = new JMenuItem("Abrir");

		mnArquivo.add(mnItemAbrir);

		JMenuItem mnItemSalvar = new JMenuItem("Salvar");
		mnArquivo.add(mnItemSalvar);

		JMenuItem mnItemSair = new JMenuItem("Sair");
		mnArquivo.add(mnItemSair);
		mnItemSair.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				System.exit(0);
			}
		});

        mainPnl = new JPanel();
        mainPnl.setBackground(new Color(170, 200, 245));
        mainPnl.setBorder(new EmptyBorder(5, 5, 5, 5));

        setContentPane(mainPnl);
        mainPnl.setLayout(null);

        JPanel pnlHdr = new JPanel();
        pnlHdr.setBounds( 0, 0, 1040, 150);
        pnlHdr.setBackground(new Color(60, 150, 200));
        mainPnl.add(pnlHdr);
        pnlHdr.setLayout(null);

        JLabel ttlLabel = new JLabel("Pokemon");
        ttlLabel.setFont(new Font("LM Sans 10", Font.BOLD, 30));
        ttlLabel.setBounds(480, 40, 438, 66);
        ttlLabel.setForeground(Color.white);
        pnlHdr.add(ttlLabel);
        ttlLabel.setLayout(null);

        ImageIcon icon = new ImageIcon(TelaPokemon.class.getResource("/img/pokemon.png"));

        Image iconImg = icon.getImage();
        Image rszImg = iconImg.getScaledInstance(70, 70, Image.SCALE_SMOOTH);
        ImageIcon rszIcon = new ImageIcon(rszImg);

        JLabel iconLbl = new JLabel("");
        iconLbl.setHorizontalAlignment(SwingConstants.CENTER);
        iconLbl.setIcon(rszIcon);
        iconLbl.setBounds(190, 40, 438, 70);
        pnlHdr.add(iconLbl);

        // Secao de adicao do pokemon
        JPanel pnl = new JPanel();
        pnl.setBounds( 40, 170, 960, 180);
        pnl.setForeground(new Color( 190, 190, 190));
        mainPnl.add(pnl);
        pnl.setLayout(null);

        JLabel lblProd = new JLabel("Novo Pokemon");
        lblProd.setFont(new Font("Dialog", Font.BOLD, 20));
        lblProd.setBounds( 20, 20, 200, 20);
        lblProd.setForeground(new Color(60, 150, 200));
        pnl.add(lblProd);

        // Nome do pokemon
        JLabel lblNome = new JLabel("Nome:");
        lblNome.setFont(new Font("Dialog", Font.BOLD, 15));
        lblNome.setBounds( 20, 60, 200, 20);
        lblNome.setForeground(new Color( 15, 15, 15));
        pnl.add(lblNome);

        txtNome = new JTextField();
        txtNome.setBounds(20, 80, 350, 25);
        txtNome.setBackground(new Color(240, 240, 240));
        pnl.add(txtNome);
        txtNome.setColumns(10);

        // Ataque do pokemon
        JLabel lblAtaque = new JLabel("Ataque:");
        lblAtaque.setFont(new Font("Dialog", Font.BOLD, 15));
        lblAtaque.setBounds(20, 120, 200, 20);
        lblAtaque.setForeground(new Color( 15, 15, 15));
        pnl.add(lblAtaque);

        txtAtaque = new JTextField();
        txtAtaque.setBounds(20, 140, 100, 25);
        txtAtaque.setBackground(new Color(240, 240, 240));
        pnl.add(txtAtaque);
        txtAtaque.setColumns(10);

        // Defesa do pokemon
        JLabel lblDefesa = new JLabel("Defesa:");
        lblDefesa.setFont(new Font("Dialog", Font.BOLD, 15));
        lblDefesa.setBounds(268, 120, 200, 20);
        lblDefesa.setForeground(new Color( 15, 15, 15));
        pnl.add(lblDefesa);

        txtDefesa = new JTextField();
        txtDefesa.setBounds(269, 140, 100, 25);
        txtDefesa.setBackground(new Color(240, 240, 240));
        pnl.add(txtDefesa);
        txtDefesa.setColumns(10);

        // Selecionar tipo pokemon
        JLabel lblTipo = new JLabel("Tipo pokemon:");
        lblTipo.setFont(new Font("Dialog", Font.BOLD, 15));
        lblTipo.setBounds(520, 60, 200, 20);
        pnl.add(lblTipo);

        // Tipo bota
        JRadioButton rdbtnTipoNormal = new JRadioButton("Normal");
        rdbtnTipoNormal.setFont(new Font("Dialog", Font.BOLD, 15));
        rdbtnTipoNormal.setBackground(new Color(240, 240, 240));
        rdbtnTipoNormal.setBounds(530, 85, 80, 20);
        pnl.add(rdbtnTipoNormal);

        // Tipo Sapatenis
        JRadioButton rdbtnTipoEletrico = new JRadioButton("Eletrico");
        rdbtnTipoEletrico.setFont(new Font("Dialog", Font.BOLD, 15));
        rdbtnTipoEletrico.setBackground(new Color(240, 240, 240));
        rdbtnTipoEletrico.setBounds(650, 85, 100, 20);
        pnl.add(rdbtnTipoEletrico);

        // Tipo Tenis
        JRadioButton rdbtnTipoTerra = new JRadioButton("Terra");
        rdbtnTipoTerra.setFont(new Font("Dialog", Font.BOLD, 15));
        rdbtnTipoTerra.setBackground(new Color(240, 240, 240));
        rdbtnTipoTerra.setBounds(530, 105, 100, 20);
        pnl.add(rdbtnTipoTerra);

        ButtonGroup btnGrp = new ButtonGroup();
        btnGrp.add(rdbtnTipoTerra);
        btnGrp.add(rdbtnTipoEletrico);
        btnGrp.add(rdbtnTipoNormal);

        // Butao Salvar
        JButton saveBtn = new JButton("Adicionar Pokemon");
        saveBtn.setFont(new Font("Dialog", Font.BOLD, 15));
        saveBtn.setBounds(600, 135, 220, 30);
        saveBtn.setBackground(new Color(60, 150, 200));
        saveBtn.setForeground(Color.white);
        pnl.add(saveBtn);

        // Table Panel
        JPanel tblPnl = new JPanel();
        tblPnl.setBounds(40, 360, 960, 300);
        tblPnl.setForeground(new Color( 190, 190, 190));
        mainPnl.add(tblPnl);
        tblPnl.setLayout(null);

        JLabel lblTbl = new JLabel("Tabela Pokemons");
        lblTbl.setFont(new Font("Dialog", Font.BOLD, 20));
        lblTbl.setBounds( 20, 20, 150, 20);
        lblTbl.setForeground(new Color(60, 150, 200));
        tblPnl.add(lblTbl);

        JScrollPane tblScrollPnl = new JScrollPane();
        tblScrollPnl.setBounds(12, 52, 940, 240);
        tblPnl.add(tblScrollPnl);

        // Modelo Tabela
        ArrayList<Normal> pokemons = new ArrayList<>();
        PokemonModel model = new PokemonModel(pokemons);

        tbl = new JTable();
        tbl.setFont(new Font("Dialog", Font.PLAIN, 15));
        tbl.setModel(model);
        tblScrollPnl.setViewportView(tbl);

        // Pesquisar
        JLabel lblSearch = new JLabel("Pesquisar:");
        lblSearch.setFont(new Font("Dialog", Font.BOLD, 17));
        lblSearch.setBounds( 425, 18, 90, 20);
        lblSearch.setForeground(new Color( 15, 15, 15));
        tblPnl.add(lblSearch);

        txtPesquisa = new JTextField();
        txtPesquisa.setBounds(520, 14, 160, 25);
        txtPesquisa.setBackground(new Color(240, 240, 240));
        tblPnl.add(txtPesquisa);
        txtPesquisa.setColumns(10);

        // Botao Pesquisar
        JButton btnPesquisar = new JButton("Pesquisar");
        btnPesquisar.setFont(new Font("Dialog", Font.BOLD, 15));
        btnPesquisar.setBounds(690, 13, 120, 27);
        btnPesquisar.setBackground(new Color(60, 180, 230));
        btnPesquisar.setForeground(Color.white);
        tblPnl.add(btnPesquisar);

        // Botao Deletar
        JButton deleteBtn = new JButton("Delete");
        deleteBtn.setFont(new Font("Dialog", Font.BOLD, 15));
        deleteBtn.setBounds(830, 13, 100, 27);
        deleteBtn.setBackground(new Color(230, 70, 60));
        deleteBtn.setForeground(Color.white);
        tblPnl.add(deleteBtn);

        // Acoes dos botoes
        // Salvar
        saveBtn.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent arg0){
                String nome = txtNome.getText().toString();
                String tipo = rdbtnTipoTerra.isSelected() ? "Terra" : (rdbtnTipoNormal.isSelected() ? "Normal" : "Eletrico");
                String ataque = txtAtaque.getText().toString();
                String defesa = txtDefesa.getText().toString();

                if(nome.isEmpty() || tipo.isEmpty() || ataque.isEmpty() || defesa.isEmpty()){
                    JOptionPane.showMessageDialog(TelaPokemon.this,
                            "Preencha todos os campos!",
                            "Messagem de Alerta!", JOptionPane.WARNING_MESSAGE);
                }else{
                    try {
                        if(tipo == "Eletrico"){
                            Eletrico pokemon = new Eletrico(nome, Double.parseDouble(ataque), Double.parseDouble(defesa));
                            model.addPokemon(pokemon);
                        }else if(tipo == "Terra"){
                            Terra pokemon = new Terra(nome, Double.parseDouble(ataque), Double.parseDouble(defesa));
                            model.addPokemon(pokemon);
                        }else{
                            Normal pokemon = new Normal(nome, Double.parseDouble(ataque), Double.parseDouble(defesa));
                            model.addPokemon(pokemon);
                        }
                    } catch (Exception e) {
                    JOptionPane.showMessageDialog(TelaPokemon.this,
                            e.getMessage(),
                            "Messagem de Alerta!", JOptionPane.WARNING_MESSAGE);
                    }

                }
            }
        });

        // Deletar
        deleteBtn.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent arg0){
                int line = tbl.getSelectedRow();
                if(line >= 0){
                    model.deletePokemon(line);
                }else{
                    JOptionPane.showMessageDialog(TelaPokemon.this,
                            "Selecione uma linha da tabela!",
                            "Mensagem de Alerta!", JOptionPane.WARNING_MESSAGE);

                }
            }
        });

        // Pesquisar
        btnPesquisar.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent arg0){
                String nome = txtPesquisa.getText().toString();
                String patternStr = "^[a-z]+$";
                Pattern pattern = Pattern.compile(patternStr);
                Matcher matcher = pattern.matcher(nome);
                System.out.println(matcher.find());
                if(!nome.isEmpty()){
                    int index = model.searchPokemon(nome);
                    tbl.setRowSelectionInterval(index, index);
                }else{
                    JOptionPane.showMessageDialog(TelaPokemon.this,
                            "Preencha o campo de pesquisa!",
                            "Mensagem de alerta!", JOptionPane.WARNING_MESSAGE);
                }
            }
        });

        // Acoes do MenuBar
        mnItemAbrir.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent arg0) {
				JFileChooser fileChooser = new JFileChooser();
				int retorno = fileChooser.showOpenDialog(TelaPokemon.this);
				if (retorno == JFileChooser.APPROVE_OPTION) {
					File file = fileChooser.getSelectedFile();
					try {
						carregarDados(file, model);
					} catch (IOException e) {
                    JOptionPane.showMessageDialog(TelaPokemon.this,
                            e.getMessage(),
                            "Messagem de Alerta!", JOptionPane.WARNING_MESSAGE);
					}
				}
			}
        });

		mnItemSalvar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				JFileChooser fileChooser = new JFileChooser();
				int retorno = fileChooser.showSaveDialog(TelaPokemon.this);
				if (retorno == JFileChooser.APPROVE_OPTION) {
					File file = fileChooser.getSelectedFile();
					salvarDados(file, model);
				}
			}
		});

    };

	private static void carregarDados(File file, PokemonModel modelo) throws IOException {
		try {
			FileReader fileReader = new FileReader(file);
			BufferedReader bufferedReader = new BufferedReader(fileReader);
			bufferedReader.readLine(); //Lê e ignora o cabeçalho do arquivo!
			modelo.limparDados();
			String linha;
			while((linha =  bufferedReader.readLine()) != null ) {
				String campos[] = linha.split(",");
				if (campos.length == 6) {
                    try {
                        if(campos[1] == "Eletrico"){
                            Eletrico pokemon = new Eletrico(campos[0],
                                    Double.parseDouble(campos[2]), Double.parseDouble(campos[3]));
                            modelo.addPokemon(pokemon);
                        }else if(campos[1] == "Terra"){
                            Terra pokemon = new Terra(campos[0],
                                    Double.parseDouble(campos[2]), Double.parseDouble(campos[3]));
                            modelo.addPokemon(pokemon);
                        }else {
                            Normal pokemon = new Normal(campos[0],
                                    Double.parseDouble(campos[2]), Double.parseDouble(campos[3]));
                            modelo.addPokemon(pokemon);
                        }

                    } catch (Exception e) {
                            e.printStackTrace();
                    }
				}
			}
			fileReader.close();
			bufferedReader.close();

		} catch (FileNotFoundException e) {
            e.printStackTrace();
		}

	}


	private static void salvarDados(File file, PokemonModel modelo) {

		try {
			FileWriter fileWriter = new FileWriter(file);
			BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);
			bufferedWriter.write("Nome, Tipo, Ataque, Defesa, Qualidade, Avaliacao");
			bufferedWriter.newLine();

			for (int i=0; i < modelo.getRowCount(); i++) {
				String nome = modelo.getValueAt(i, 0).toString();
				String tipo = modelo.getValueAt(i, 1).toString();
				String ataque = modelo.getValueAt(i, 2).toString();
				String defesa = modelo.getValueAt(i, 3).toString();
				String qualidade = modelo.getValueAt(i, 4).toString();
				String avaliacao = modelo.getValueAt(i, 5).toString();
				bufferedWriter.write(nome+","+tipo+","+ataque+","+defesa+","+qualidade+","+avaliacao);
				System.out.println(nome+","+tipo+","+ataque+","+defesa+","+qualidade+","+avaliacao);
				bufferedWriter.newLine();
			}
			JOptionPane.showMessageDialog(null, "Dados salvos com sucesso!",
                    "Salvar dados", JOptionPane.INFORMATION_MESSAGE);
			bufferedWriter.close();
			fileWriter.close();

        } catch (IOException e) {
            e.printStackTrace();
		}


	}

}
