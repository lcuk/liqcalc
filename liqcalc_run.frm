VERSION 5.00
Begin VB.Form liqcalc_run 
   BackColor       =   &H00000000&
   BorderStyle     =   1  'Fixed Single
   Caption         =   "Base Form"
   ClientHeight    =   12015
   ClientLeft      =   45
   ClientTop       =   360
   ClientWidth     =   7200
   BeginProperty Font 
      Name            =   "Trebuchet MS"
      Size            =   9.75
      Charset         =   0
      Weight          =   400
      Underline       =   0   'False
      Italic          =   0   'False
      Strikethrough   =   0   'False
   EndProperty
   LinkTopic       =   "frmBase800x480"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   12015
   ScaleWidth      =   7200
   StartUpPosition =   3  'Windows Default
   Begin VB.TextBox liqbasepassword 
      Alignment       =   1  'Right Justify
      BeginProperty Font 
         Name            =   "Trebuchet MS"
         Size            =   48
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   1335
      Left            =   1410
      TabIndex        =   0
      Text            =   "12345678"
      Top             =   960
      Width           =   4965
   End
   Begin VB.Label title 
      BackColor       =   &H00008080&
      Caption         =   "liqcalc"
      BeginProperty Font 
         Name            =   "Trebuchet MS"
         Size            =   27.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   840
      Left            =   0
      TabIndex        =   29
      Top             =   0
      Width           =   7200
   End
   Begin VB.Label cmdequals 
      Alignment       =   2  'Center
      BackColor       =   &H00008000&
      Caption         =   "="
      BeginProperty Font 
         Name            =   "Trebuchet MS"
         Size            =   27.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H0000FFFF&
      Height          =   1305
      Left            =   3840
      TabIndex        =   28
      Top             =   10500
      Width           =   1395
   End
   Begin VB.Label cmddot 
      Alignment       =   2  'Center
      BackColor       =   &H00404040&
      Caption         =   "."
      BeginProperty Font 
         Name            =   "Trebuchet MS"
         Size            =   27.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H0000FFFF&
      Height          =   1305
      Left            =   2100
      TabIndex        =   27
      Top             =   10500
      Width           =   1395
   End
   Begin VB.Label cmd0 
      Alignment       =   2  'Center
      BackColor       =   &H00404040&
      Caption         =   "0"
      BeginProperty Font 
         Name            =   "Trebuchet MS"
         Size            =   27.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H0000FFFF&
      Height          =   1305
      Left            =   300
      TabIndex        =   26
      Top             =   10500
      Width           =   1395
   End
   Begin VB.Label cmd3 
      Alignment       =   2  'Center
      BackColor       =   &H00404040&
      Caption         =   "3"
      BeginProperty Font 
         Name            =   "Trebuchet MS"
         Size            =   27.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H0000FFFF&
      Height          =   1305
      Left            =   3840
      TabIndex        =   25
      Top             =   8970
      Width           =   1395
   End
   Begin VB.Label cmd2 
      Alignment       =   2  'Center
      BackColor       =   &H00404040&
      Caption         =   "2"
      BeginProperty Font 
         Name            =   "Trebuchet MS"
         Size            =   27.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H0000FFFF&
      Height          =   1305
      Left            =   2100
      TabIndex        =   24
      Top             =   8970
      Width           =   1395
   End
   Begin VB.Label cmd1 
      Alignment       =   2  'Center
      BackColor       =   &H00404040&
      Caption         =   "1"
      BeginProperty Font 
         Name            =   "Trebuchet MS"
         Size            =   27.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H0000FFFF&
      Height          =   1305
      Left            =   300
      TabIndex        =   23
      Top             =   8970
      Width           =   1395
   End
   Begin VB.Label cmd6 
      Alignment       =   2  'Center
      BackColor       =   &H00404040&
      Caption         =   "6"
      BeginProperty Font 
         Name            =   "Trebuchet MS"
         Size            =   27.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H0000FFFF&
      Height          =   1305
      Left            =   3840
      TabIndex        =   22
      Top             =   7440
      Width           =   1395
   End
   Begin VB.Label cmd5 
      Alignment       =   2  'Center
      BackColor       =   &H00404040&
      Caption         =   "5"
      BeginProperty Font 
         Name            =   "Trebuchet MS"
         Size            =   27.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H0000FFFF&
      Height          =   1305
      Left            =   2100
      TabIndex        =   21
      Top             =   7440
      Width           =   1395
   End
   Begin VB.Label cmd4 
      Alignment       =   2  'Center
      BackColor       =   &H00404040&
      Caption         =   "4"
      BeginProperty Font 
         Name            =   "Trebuchet MS"
         Size            =   27.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H0000FFFF&
      Height          =   1305
      Left            =   300
      TabIndex        =   20
      Top             =   7440
      Width           =   1395
   End
   Begin VB.Label cmd9 
      Alignment       =   2  'Center
      BackColor       =   &H00404040&
      Caption         =   "9"
      BeginProperty Font 
         Name            =   "Trebuchet MS"
         Size            =   27.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H0000FFFF&
      Height          =   1305
      Left            =   3840
      TabIndex        =   19
      Top             =   5910
      Width           =   1395
   End
   Begin VB.Label cmd8 
      Alignment       =   2  'Center
      BackColor       =   &H00404040&
      Caption         =   "8"
      BeginProperty Font 
         Name            =   "Trebuchet MS"
         Size            =   27.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H0000FFFF&
      Height          =   1305
      Left            =   2100
      TabIndex        =   18
      Top             =   5910
      Width           =   1395
   End
   Begin VB.Label cmd7 
      Alignment       =   2  'Center
      BackColor       =   &H00404040&
      Caption         =   "7"
      BeginProperty Font 
         Name            =   "Trebuchet MS"
         Size            =   27.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H0000FFFF&
      Height          =   1305
      Left            =   300
      TabIndex        =   17
      Top             =   5910
      Width           =   1395
   End
   Begin VB.Label cmdplus 
      Alignment       =   2  'Center
      BackColor       =   &H00404040&
      Caption         =   "+"
      BeginProperty Font 
         Name            =   "Trebuchet MS"
         Size            =   27.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H0000FFFF&
      Height          =   2865
      Left            =   5550
      TabIndex        =   16
      Top             =   8940
      Width           =   1395
   End
   Begin VB.Label cmdminus 
      Alignment       =   2  'Center
      BackColor       =   &H00404040&
      Caption         =   "-"
      BeginProperty Font 
         Name            =   "Trebuchet MS"
         Size            =   27.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H0000FFFF&
      Height          =   1305
      Left            =   5550
      TabIndex        =   15
      Top             =   7440
      Width           =   1395
   End
   Begin VB.Label cmdmul 
      Alignment       =   2  'Center
      BackColor       =   &H00404040&
      Caption         =   "X"
      BeginProperty Font 
         Name            =   "Trebuchet MS"
         Size            =   27.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H0000FFFF&
      Height          =   1305
      Left            =   5550
      TabIndex        =   14
      Top             =   5910
      Width           =   1395
   End
   Begin VB.Label cmdpercent 
      Alignment       =   2  'Center
      BackColor       =   &H00404040&
      Caption         =   "%"
      BeginProperty Font 
         Name            =   "Trebuchet MS"
         Size            =   27.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H0000FFFF&
      Height          =   1305
      Left            =   3840
      TabIndex        =   13
      Top             =   4380
      Width           =   1395
   End
   Begin VB.Label cmdc 
      Alignment       =   2  'Center
      BackColor       =   &H00004080&
      Caption         =   "C"
      BeginProperty Font 
         Name            =   "Trebuchet MS"
         Size            =   27.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H0000FFFF&
      Height          =   1305
      Left            =   2100
      TabIndex        =   12
      Top             =   4380
      Width           =   1395
   End
   Begin VB.Label cmdac 
      Alignment       =   2  'Center
      BackColor       =   &H00004080&
      Caption         =   "AC"
      BeginProperty Font 
         Name            =   "Trebuchet MS"
         Size            =   27.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H0000FFFF&
      Height          =   1305
      Left            =   300
      TabIndex        =   11
      Top             =   4380
      Width           =   1395
   End
   Begin VB.Label cmddivide 
      Alignment       =   2  'Center
      BackColor       =   &H00404040&
      Caption         =   "÷"
      BeginProperty Font 
         Name            =   "Trebuchet MS"
         Size            =   27.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H0000FFFF&
      Height          =   1305
      Left            =   5550
      TabIndex        =   10
      Top             =   4380
      Width           =   1395
   End
   Begin VB.Label cmdmplus 
      Alignment       =   2  'Center
      BackColor       =   &H00800000&
      Caption         =   "M+"
      BeginProperty Font 
         Name            =   "Trebuchet MS"
         Size            =   21.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H0000FFFF&
      Height          =   645
      Left            =   2880
      TabIndex        =   9
      Top             =   3480
      Width           =   1185
   End
   Begin VB.Label cmdmneg 
      Alignment       =   2  'Center
      BackColor       =   &H00800000&
      Caption         =   "M-"
      BeginProperty Font 
         Name            =   "Trebuchet MS"
         Size            =   21.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H0000FFFF&
      Height          =   645
      Left            =   1590
      TabIndex        =   8
      Top             =   3480
      Width           =   1185
   End
   Begin VB.Label cmdmrc 
      Alignment       =   2  'Center
      BackColor       =   &H00800000&
      Caption         =   "MRC"
      BeginProperty Font 
         Name            =   "Trebuchet MS"
         Size            =   21.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H0000FFFF&
      Height          =   645
      Left            =   300
      TabIndex        =   7
      Top             =   3480
      Width           =   1185
   End
   Begin VB.Label cmdsqr 
      Alignment       =   2  'Center
      BackColor       =   &H00404040&
      Caption         =   "^2"
      BeginProperty Font 
         Name            =   "Trebuchet MS"
         Size            =   21.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H0000FFFF&
      Height          =   645
      Left            =   4440
      TabIndex        =   6
      Top             =   3480
      Width           =   1185
   End
   Begin VB.Label Label26 
      Alignment       =   2  'Center
      BackColor       =   &H00FFFFFF&
      Caption         =   "-"
      BeginProperty Font 
         Name            =   "Trebuchet MS"
         Size            =   21.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00000000&
      Height          =   555
      Left            =   750
      TabIndex        =   5
      Top             =   1320
      Width           =   675
   End
   Begin VB.Label Label4 
      Alignment       =   2  'Center
      BackColor       =   &H00FFFFFF&
      Caption         =   "M"
      BeginProperty Font 
         Name            =   "Trebuchet MS"
         Size            =   21.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00000000&
      Height          =   555
      Left            =   750
      TabIndex        =   4
      Top             =   960
      Width           =   675
   End
   Begin VB.Label Label21 
      Alignment       =   2  'Center
      BackColor       =   &H00FFFFFF&
      Caption         =   "E"
      BeginProperty Font 
         Name            =   "Trebuchet MS"
         Size            =   21.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00000000&
      Height          =   555
      Left            =   750
      TabIndex        =   3
      Top             =   1740
      Width           =   675
   End
   Begin VB.Label cmdplusminus 
      Alignment       =   2  'Center
      BackColor       =   &H00404040&
      Caption         =   "±"
      BeginProperty Font 
         Name            =   "Trebuchet MS"
         Size            =   21.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H0000FFFF&
      Height          =   645
      Left            =   5760
      TabIndex        =   2
      Top             =   3480
      Width           =   1185
   End
   Begin VB.Label Label28 
      Alignment       =   2  'Center
      BackColor       =   &H00404040&
      Caption         =   "SOLAR CELL"
      BeginProperty Font 
         Name            =   "Trebuchet MS"
         Size            =   26.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00808080&
      Height          =   765
      Left            =   3120
      TabIndex        =   1
      Top             =   2490
      Width           =   3825
   End
End
Attribute VB_Name = "liqcalc_run"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

