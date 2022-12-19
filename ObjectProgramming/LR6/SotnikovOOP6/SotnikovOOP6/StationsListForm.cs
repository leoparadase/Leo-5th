using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Runtime.InteropServices;

namespace SotnikovOOP6
{
    public partial class StationsListForm : Form
    {
        sotnikovMetroSys MetroSys = new sotnikovMetroSys();


        // ORIGIN FUNCTIONS

        [DllImport("MFCLibrary1.dll", CharSet = CharSet.Ansi)]
        private static extern void Load_From_File(StringBuilder path);

        [DllImport("MFCLibrary1.dll", CharSet = CharSet.Ansi)]
        private static extern void Save_To_File(StringBuilder path);

        [DllImport("MFCLibrary1.dll", CharSet = CharSet.Ansi)]
        private static extern void Clear();


        // GET - FUNCTIONS

        [DllImport("MFCLibrary1.dll", CharSet = CharSet.Ansi)]
        private static extern int Get_Container_Size();

        [DllImport("MFCLibrary1.dll", CharSet = CharSet.Ansi)]
        private static extern bool Get_Element_Type(int index);

        [DllImport("MFCLibrary1.dll", CharSet = CharSet.Ansi)]
        private static extern int Get_Station_ID(int index);

        [DllImport("MFCLibrary1.dll", CharSet = CharSet.Ansi)]
        private static extern void Get_Station_Name(int index, StringBuilder str);

        [DllImport("MFCLibrary1.dll", CharSet = CharSet.Ansi)]
        private static extern int Get_Station_Line(int index);

        [DllImport("MFCLibrary1.dll", CharSet = CharSet.Ansi)]
        private static extern int Get_Station_Category(int index);


        // CREATING OBJECTS

        [DllImport("MFCLibrary1.dll", CharSet = CharSet.Ansi)]
        private static extern void Create_Station();

        [DllImport("MFCLibrary1.dll", CharSet = CharSet.Ansi)]
        private static extern void Create_Tech_Station();

        // SET FUNCTIONS

        [DllImport("MFCLibrary1.dll", CharSet = CharSet.Ansi)]
        private static extern void Set_Station_ID(int index, int new_id);

        [DllImport("MFCLibrary1.dll", CharSet = CharSet.Ansi)]
        private static extern void Set_Station_Name(int index, StringBuilder str);

        [DllImport("MFCLibrary1.dll", CharSet = CharSet.Ansi)]
        private static extern void Set_Station_Line(int index, int new_line);

        [DllImport("MFCLibrary1.dll", CharSet = CharSet.Ansi)]
        private static extern void Set_Station_Category(int index, int new_category);

        public StationsListForm()
        {
            InitializeComponent();
            Refresh_list();

            if (sotnikovMetroSys.stations.Count == 0)
            {
                StationsListBox1.SelectedIndex = -1;
            }
            else
            {
                StationsListBox1.SelectedIndex = sotnikovMetroSys.stations.Count - 1;
            }
        }

        public void Refresh_list()
        {
            StationsListBox1.Items.Clear();

            if (sotnikovMetroSys.stations.Count == 0)
            {
                textBoxID.Visible = false;
                textBoxName.Visible = false;
                textBoxLine.Visible = false;
                textBoxCategory.Visible = false;

                labelID.Visible = false;
                labelName.Visible = false;
                labelLine.Visible = false;
                labelCategory.Visible = false;

                // look for buttons, when container is empty, THEN CHECK ELSE

                buttonChange.Enabled = false;
                buttonDelete.Enabled = false;
                buttonOK.Enabled = false;
            }
            else
            {
                foreach (sotnikovStation station in sotnikovMetroSys.stations)
                {
                    textBoxID.Visible = true;
                    textBoxName.Visible = true;
                    textBoxLine.Visible = true;
                    textBoxCategory.Visible = true;

                    labelID.Visible = true;
                    labelName.Visible = true;
                    labelLine.Visible = true;
                    labelCategory.Visible = true;

                    StationsListBox1.Items.Add(station.name);

                    buttonChange.Enabled = true;
                    buttonDelete.Enabled = true;
                    buttonOK.Enabled = true;
                }
            }
        }

        public void OriginalElements()
        {
            textBoxID.Visible = true;
            textBoxName.Visible = true;
            textBoxLine.Visible = true;
            textBoxCategory.Visible = false;

            labelID.Visible = true;
            labelName.Visible = true;
            labelLine.Visible = true;
            labelCategory.Visible = false;
        }

        public void DerivedElements()
        {
            textBoxID.Visible = true;
            textBoxName.Visible = true;
            textBoxLine.Visible = true;
            textBoxCategory.Visible = true;

            labelID.Visible = true;
            labelName.Visible = true;
            labelLine.Visible = true;
            labelCategory.Visible = true;
        }



        private void StationsListForm_Load(object sender, EventArgs e)
        {
            Refresh_list();
            if (sotnikovMetroSys.stations.Count == 0)
            {
                StationsListBox1.SelectedIndex = -1;
            }
            else
            {
                StationsListBox1.SelectedIndex = sotnikovMetroSys.stations.Count - 1;
            }
        }

        private void StationsListForm_Activated(object sender, EventArgs e)
        {
            Refresh_list();
            if (sotnikovMetroSys.stations.Count == 0)
            {
                StationsListBox1.SelectedIndex = -1;
            }
            else
            {
                StationsListBox1.SelectedIndex = sotnikovMetroSys.stations.Count - 1;
            }
        }

        private void StationsListBox1_SelectedValueChanged(object sender, EventArgs e)
        {
            int index = StationsListBox1.SelectedIndex;

            if (MetroSys.GetElementType(index))
            {
                sotnikovTechStation n;
                n = MetroSys.GetElement(index) as sotnikovTechStation;

                DerivedElements();
                textBoxID.Text = Convert.ToString(n.id);
                textBoxName.Text = n.name; ;
                textBoxLine.Text = Convert.ToString(n.line);
                textBoxCategory.Text = Convert.ToString(n.category);
            }
            else
            {
                sotnikovStation n;
                n = MetroSys.GetElement(index) as sotnikovStation;

                OriginalElements();
                textBoxID.Text = Convert.ToString(n.id);
                textBoxName.Text = n.name; ;
                textBoxLine.Text = Convert.ToString(n.line);
            }
        }

        private void buttonDelete_Click(object sender, EventArgs e)
        {
            int index = StationsListBox1.SelectedIndex;

            if (index >= 0)
            {
                MetroSys.Delete(index);
                Refresh_list();

                if ((index < sotnikovMetroSys.stations.Count))
                    StationsListBox1.SelectedIndex = index;
                else
                    StationsListBox1.SelectedIndex = index - 1;
            }
        }

        public bool ch = false;

        private void buttonChange_Click(object sender, EventArgs e)
        {
            int edit_id = StationsListBox1.SelectedIndex;
            AddStationForm add_form = new AddStationForm(false, edit_id); // look for form's code
            ch = true;
            add_form.flag_edit = true;

            add_form.Show();
        }

        private void buttonOpenFile_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog1 = new OpenFileDialog();
            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                var name_file = new StringBuilder(openFileDialog1.FileName);
                Load_From_File(name_file);
                int count = Get_Container_Size();

                for (int i = 0; i < count; i++)
                {
                    if (Get_Station_Category(i) < 0)
                    {
                        sotnikovStation s = new sotnikovStation();

                        s.id = Get_Station_ID(i);

                        var str = new StringBuilder(256);
                        Get_Station_Name(i, str);
                        s.name = str.ToString();

                        s.line = Get_Station_Line(i);

                        sotnikovMetroSys.stations.Add(s);
                    }
                    else
                    {
                        sotnikovTechStation s = new sotnikovTechStation();

                        s.id = Get_Station_ID(i);

                        var str = new StringBuilder(256);
                        Get_Station_Name(i, str);
                        s.name = str.ToString();

                        s.line = Get_Station_Line(i);
                        s.category = Get_Station_Category(i);

                        sotnikovMetroSys.stations.Add(s);
                    }
                }

                Refresh_list();
                StationsListBox1.SelectedIndex = sotnikovMetroSys.stations.Count - 1;
            }
        }

        private void buttonSave_Click(object sender, EventArgs e)
        {
            SaveFileDialog saveFileDialog1 = new SaveFileDialog();
            if (saveFileDialog1.ShowDialog() == DialogResult.OK)
            {
                Clear();

                for (int i = 0; i < sotnikovMetroSys.stations.Count; i++)
                {
                    if (sotnikovMetroSys.stations[i].GetType() == typeof(sotnikovStation))
                    {
                        Create_Station();
                        sotnikovStation cur_element = sotnikovMetroSys.stations[i] as sotnikovStation;

                        Set_Station_ID(i, cur_element.id);

                        var str = new StringBuilder();
                        str.Append(cur_element.name);
                        Set_Station_Name(i, str);

                        Set_Station_Line(i, cur_element.line);
                    }
                    else
                    {
                        Create_Tech_Station();
                        sotnikovTechStation cur_element = sotnikovMetroSys.stations[i] as sotnikovTechStation;

                        Set_Station_ID(i, cur_element.id);

                        var str = new StringBuilder();
                        str.Append(cur_element.name);
                        Set_Station_Name(i, str);

                        Set_Station_Line(i, cur_element.line);
                        Set_Station_Category(i, cur_element.category);
                    }
                }

                var name_file = new StringBuilder(saveFileDialog1.FileName);
                Save_To_File(name_file);
                Clear();
            }
        }

        private void buttonOK_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void buttonAddNew_Click(object sender, EventArgs e)
        {
            AddStationForm add_f = new AddStationForm(true, 0);
            add_f.Show();
        }
    }
}
