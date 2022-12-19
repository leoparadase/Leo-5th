using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace SotnikovOOP6
{
    public partial class AddStationForm : Form
    {
        bool isnew;
        int id;
        public bool flag_edit = false;

        public AddStationForm(bool addnew, int edit_id)
        {
            InitializeComponent();
            isnew = addnew;
            id = edit_id;
            if (!isnew)
            {
                checkBoxIsTech.Hide();
                ShowInfo(edit_id);
            }
            else checkBoxIsTech.Checked = true;
        }

        public void ShowInfo(int edit_id)
        {
            if (sotnikovMetroSys.stations[edit_id].GetType() == typeof(sotnikovStation))
            {
                sotnikovStation s;
                s = sotnikovMetroSys.stations[edit_id] as sotnikovStation;

                textBoxID.Text = Convert.ToString(s.id);
                textBoxName.Text = s.name;
                textBoxLine.Text = Convert.ToString(s.line);

                checkBoxIsTech.Checked = false;
                labelChangeCategory.Visible = false;
                textBoxCategory.Visible = false;
            }
            else
            {
                sotnikovTechStation s;
                s = sotnikovMetroSys.stations[edit_id] as sotnikovTechStation;

                textBoxID.Text = Convert.ToString(s.id);
                textBoxName.Text = s.name;
                textBoxLine.Text = Convert.ToString(s.line);
                textBoxCategory.Text = Convert.ToString(s.category);

                checkBoxIsTech.Checked = true;
                labelChangeCategory.Visible = true;
                textBoxCategory.Visible = true;
            }
        }

        private void SaveNew(object sender, EventArgs e)
        {
            if (checkBoxIsTech.Checked)
            {
                sotnikovTechStation s = new sotnikovTechStation();

                s.id = Convert.ToInt32(textBoxID.Text);
                s.name = textBoxName.Text;
                s.line = Convert.ToInt32(textBoxLine.Text);
                s.category = Convert.ToInt32(textBoxCategory.Text);

                sotnikovMetroSys.AddStation(s);
            }
            else
            {
                sotnikovStation s = new sotnikovStation();

                s.id = Convert.ToInt32(textBoxID.Text);
                s.name = textBoxName.Text;
                s.line = Convert.ToInt32(textBoxLine.Text);

                sotnikovMetroSys.AddStation(s);
            }

            StationsListForm form = new StationsListForm();
            Close();
        }

        private void SaveChanged(object sender, EventArgs e)
        {
            if (checkBoxIsTech.Checked)
            {
                sotnikovTechStation s;
                s = sotnikovMetroSys.stations[id] as sotnikovTechStation;

                s.id = Convert.ToInt32(textBoxID.Text);
                s.name = textBoxName.Text;
                s.line = Convert.ToInt32(textBoxLine.Text);
                s.category = Convert.ToInt32(textBoxCategory.Text);
            }
            else
            {
                sotnikovStation s;
                s = sotnikovMetroSys.stations[id] as sotnikovStation;

                s.id = Convert.ToInt32(textBoxID.Text);
                s.name = textBoxName.Text;
                s.line = Convert.ToInt32(textBoxLine.Text);
            }

            Close();
        }

        private void buttonApplyChanges_Click(object sender, EventArgs e)
        {
            if (isnew) SaveNew(sender, e);
            else SaveChanged(sender, e);
        }

        private void AddStationForm_Load(object sender, EventArgs e)
        {
            if (!isnew)
            {

                ShowInfo(id);
            }
        }

        private void checkBoxIsTech_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBoxIsTech.Checked)
            {
                labelChangeCategory.Visible = true;
                textBoxCategory.Visible = true;
            }
            else
            {
                labelChangeCategory.Visible = false;
                textBoxCategory.Visible = false;
            }
        }


    }
}
