namespace WinFormsApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.Hide();
            NewUser newUser = new NewUser();
            newUser.Show();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.Hide();
            OldUser ou = new OldUser();
            ou.Show();
        }

        private void label1_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }
    }
}
