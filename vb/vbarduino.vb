Public Class Form1

    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        Dim com1 As IO.Ports.SerialPort = Nothing
        Dim returnStr As String
        Dim lectura As String

        Try
            com1 = My.Computer.Ports.OpenSerialPort("COM4")
            com1.ReadTimeout = 10000
            lectura = Chr(com1.ReadByte) + Chr(com1.ReadByte) + Chr(com1.ReadByte) +
                Chr(com1.ReadByte) + Chr(com1.ReadByte) + Chr(com1.ReadByte) + Chr(com1.ReadByte)

            MsgBox(lectura,MsgBoxStyle.Information)

        Catch ex As TimeoutException
            returnStr = "Error: Serial Port sobrepasó tiempo."
        Finally
            If com1 IsNot Nothing Then com1.Close()
        End Try

    End Sub
End Class
