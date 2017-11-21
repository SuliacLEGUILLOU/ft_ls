/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 15:27:02 by msorin            #+#    #+#             */
/*   Updated: 2017/11/20 15:27:03 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//17000001
//385875969

#include <unistd.h>

#define K00  "\x1B[00m"
#define K01  "\x1B[01m"
#define K02  "\x1B[02m"
#define K03  "\x1B[03m"
#define K04  "\x1B[04m"
#define K05  "\x1B[05m"
#define K06  "\x1B[06m"
#define K07  "\x1B[07m"
#define K08  "\x1B[08m"
#define K09  "\x1B[09m"
#define K0A  "\x1B[0Am"
#define K0B  "\x1B[0Bm"
#define K0C  "\x1B[0Cm"
#define K0D  "\x1B[0Dm"
#define K0E  "\x1B[0Em"
#define K0F  "\x1B[0Fm"
#define K10  "\x1B[10m"
#define K11  "\x1B[11m"
#define K12  "\x1B[12m"
#define K13  "\x1B[13m"
#define K14  "\x1B[14m"
#define K15  "\x1B[15m"
#define K16  "\x1B[16m"
#define K17  "\x1B[17m"
#define K18  "\x1B[18m"
#define K19  "\x1B[19m"
#define K1A  "\x1B[1Am"
#define K1B  "\x1B[1Bm"
#define K1C  "\x1B[1Cm"
#define K1D  "\x1B[1Dm"
#define K1E  "\x1B[1Em"
#define K1F  "\x1B[1Fm"
#define K20  "\x1B[20m"
#define K21  "\x1B[21m"
#define K22  "\x1B[22m"
#define K23  "\x1B[23m"
#define K24  "\x1B[24m"
#define K25  "\x1B[25m"
#define K26  "\x1B[26m"
#define K27  "\x1B[27m"
#define K28  "\x1B[28m"
#define K29  "\x1B[29m"
#define K2A  "\x1B[2Am"
#define K2B  "\x1B[2Bm"
#define K2C  "\x1B[2Cm"
#define K2D  "\x1B[2Dm"
#define K2E  "\x1B[2Em"
#define K2F  "\x1B[2Fm"
#define K30  "\x1B[30m"
#define K31  "\x1B[31m"
#define K32  "\x1B[32m"
#define K33  "\x1B[33m"
#define K34  "\x1B[34m"
#define K35  "\x1B[35m"
#define K36  "\x1B[36m"
#define K37  "\x1B[37m"
#define K38  "\x1B[38m"
#define K39  "\x1B[39m"
#define K3A  "\x1B[3Am"
#define K3B  "\x1B[3Bm"
#define K3C  "\x1B[3Cm"
#define K3D  "\x1B[3Dm"
#define K3E  "\x1B[3Em"
#define K3F  "\x1B[3Fm"
#define K40  "\x1B[40m"
#define K41  "\x1B[41m"
#define K42  "\x1B[42m"
#define K43  "\x1B[43m"
#define K44  "\x1B[44m"
#define K45  "\x1B[45m"
#define K46  "\x1B[46m"
#define K47  "\x1B[47m"
#define K48  "\x1B[48m"
#define K49  "\x1B[49m"
#define K4A  "\x1B[4Am"
#define K4B  "\x1B[4Bm"
#define K4C  "\x1B[4Cm"
#define K4D  "\x1B[4Dm"
#define K4E  "\x1B[4Em"
#define K4F  "\x1B[4Fm"
#define K50  "\x1B[50m"
#define K51  "\x1B[51m"
#define K52  "\x1B[52m"
#define K53  "\x1B[53m"
#define K54  "\x1B[54m"
#define K55  "\x1B[55m"
#define K56  "\x1B[56m"
#define K57  "\x1B[57m"
#define K58  "\x1B[58m"
#define K59  "\x1B[59m"
#define K5A  "\x1B[5Am"
#define K5B  "\x1B[5Bm"
#define K5C  "\x1B[5Cm"
#define K5D  "\x1B[5Dm"
#define K5E  "\x1B[5Em"
#define K5F  "\x1B[5Fm"
#define K60  "\x1B[60m"
#define K61  "\x1B[61m"
#define K62  "\x1B[62m"
#define K63  "\x1B[63m"
#define K64  "\x1B[64m"
#define K65  "\x1B[65m"
#define K66  "\x1B[66m"
#define K67  "\x1B[67m"
#define K68  "\x1B[68m"
#define K69  "\x1B[69m"
#define K6A  "\x1B[6Am"
#define K6B  "\x1B[6Bm"
#define K6C  "\x1B[6Cm"
#define K6D  "\x1B[6Dm"
#define K6E  "\x1B[6Em"
#define K6F  "\x1B[6Fm"
#define K70  "\x1B[70m"
#define K71  "\x1B[71m"
#define K72  "\x1B[72m"
#define K73  "\x1B[73m"
#define K74  "\x1B[74m"
#define K75  "\x1B[75m"
#define K76  "\x1B[76m"
#define K77  "\x1B[77m"
#define K78  "\x1B[78m"
#define K79  "\x1B[79m"
#define K7A  "\x1B[7Am"
#define K7B  "\x1B[7Bm"
#define K7C  "\x1B[7Cm"
#define K7D  "\x1B[7Dm"
#define K7E  "\x1B[7Em"
#define K7F  "\x1B[7Fm"
#define K80  "\x1B[80m"
#define K81  "\x1B[81m"
#define K82  "\x1B[82m"
#define K83  "\x1B[83m"
#define K84  "\x1B[84m"
#define K85  "\x1B[85m"
#define K86  "\x1B[86m"
#define K87  "\x1B[87m"
#define K88  "\x1B[88m"
#define K89  "\x1B[89m"
#define K8A  "\x1B[8Am"
#define K8B  "\x1B[8Bm"
#define K8C  "\x1B[8Cm"
#define K8D  "\x1B[8Dm"
#define K8E  "\x1B[8Em"
#define K8F  "\x1B[8Fm"
#define K90  "\x1B[90m"
#define K91  "\x1B[91m"
#define K92  "\x1B[92m"
#define K93  "\x1B[93m"
#define K94  "\x1B[94m"
#define K95  "\x1B[95m"
#define K96  "\x1B[96m"
#define K97  "\x1B[97m"
#define K98  "\x1B[98m"
#define K99  "\x1B[99m"
#define K9A  "\x1B[9Am"
#define K9B  "\x1B[9Bm"
#define K9C  "\x1B[9Cm"
#define K9D  "\x1B[9Dm"
#define K9E  "\x1B[9Em"
#define K9F  "\x1B[9Fm"
#define KA0  "\x1B[A0m"
#define KA1  "\x1B[A1m"
#define KA2  "\x1B[A2m"
#define KA3  "\x1B[A3m"
#define KA4  "\x1B[A4m"
#define KA5  "\x1B[A5m"
#define KA6  "\x1B[A6m"
#define KA7  "\x1B[A7m"
#define KA8  "\x1B[A8m"
#define KA9  "\x1B[A9m"
#define KAA  "\x1B[AAm"
#define KAB  "\x1B[ABm"
#define KAC  "\x1B[ACm"
#define KAD  "\x1B[ADm"
#define KAE  "\x1B[AEm"
#define KAF  "\x1B[AFm"
#define KB0  "\x1B[B0m"
#define KB1  "\x1B[B1m"
#define KB2  "\x1B[B2m"
#define KB3  "\x1B[B3m"
#define KB4  "\x1B[B4m"
#define KB5  "\x1B[B5m"
#define KB6  "\x1B[B6m"
#define KB7  "\x1B[B7m"
#define KB8  "\x1B[B8m"
#define KB9  "\x1B[B9m"
#define KBA  "\x1B[BAm"
#define KBB  "\x1B[BBm"
#define KBC  "\x1B[BCm"
#define KBD  "\x1B[BDm"
#define KBE  "\x1B[BEm"
#define KBF  "\x1B[BFm"
#define KC0  "\x1B[C0m"
#define KC1  "\x1B[C1m"
#define KC2  "\x1B[C2m"
#define KC3  "\x1B[C3m"
#define KC4  "\x1B[C4m"
#define KC5  "\x1B[C5m"
#define KC6  "\x1B[C6m"
#define KC7  "\x1B[C7m"
#define KC8  "\x1B[C8m"
#define KC9  "\x1B[C9m"
#define KCA  "\x1B[CAm"
#define KCB  "\x1B[CBm"
#define KCC  "\x1B[CCm"
#define KCD  "\x1B[CDm"
#define KCE  "\x1B[CEm"
#define KCF  "\x1B[CFm"
#define KD0  "\x1B[D0m"
#define KD1  "\x1B[D1m"
#define KD2  "\x1B[D2m"
#define KD3  "\x1B[D3m"
#define KD4  "\x1B[D4m"
#define KD5  "\x1B[D5m"
#define KD6  "\x1B[D6m"
#define KD7  "\x1B[D7m"
#define KD8  "\x1B[D8m"
#define KD9  "\x1B[D9m"
#define KDA  "\x1B[DAm"
#define KDB  "\x1B[DBm"
#define KDC  "\x1B[DCm"
#define KDD  "\x1B[DDm"
#define KDE  "\x1B[DEm"
#define KDF  "\x1B[DFm"
#define KE0  "\x1B[E0m"
#define KE1  "\x1B[E1m"
#define KE2  "\x1B[E2m"
#define KE3  "\x1B[E3m"
#define KE4  "\x1B[E4m"
#define KE5  "\x1B[E5m"
#define KE6  "\x1B[E6m"
#define KE7  "\x1B[E7m"
#define KE8  "\x1B[E8m"
#define KE9  "\x1B[E9m"
#define KEA  "\x1B[EAm"
#define KEB  "\x1B[EBm"
#define KEC  "\x1B[ECm"
#define KED  "\x1B[EDm"
#define KEE  "\x1B[EEm"
#define KEF  "\x1B[EFm"
#define KF0  "\x1B[F0m"
#define KF1  "\x1B[F1m"
#define KF2  "\x1B[F2m"
#define KF3  "\x1B[F3m"
#define KF4  "\x1B[F4m"
#define KF5  "\x1B[F5m"
#define KF6  "\x1B[F6m"
#define KF7  "\x1B[F7m"
#define KF8  "\x1B[F8m"
#define KF9  "\x1B[F9m"
#define KFA  "\x1B[FAm"
#define KFB  "\x1B[FBm"
#define KFC  "\x1B[FCm"
#define KFD  "\x1B[FDm"
#define KFE  "\x1B[FEm"
#define KFF  "\x1B[FFm"
#define RESET "\033[0m"

#define CHTAB chtab[256][5] = {K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K0E, K0F, K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, K1E, K1F, K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, K2D, K2E, K2F, K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D, K3E, K3F, K40, K41, K42, K43, K44, K45, K46, K47, K48, K49, K4A, K4B, K4C, K4D, K4E, K4F, K50, K51, K52, K53, K54, K55, K56, K57, K58, K59, K5A, K5B, K5C, K5D, K5E, K5F, K60, K61, K62, K63, K64, K65, K66, K67, K68, K69, K6A, K6B, K6C, K6D, K6E, K6F, K70, K71, K72, K73, K74, K75, K76, K77, K78, K79, K7A, K7B, K7C, K7D, K7E, K7F, K80, K81, K82, K83, K84, K85, K86, K87, K88, K89, K8A, K8B, K8C, K8D, K8E, K8F, K90, K91, K92, K93, K94, K95, K96, K97, K98, K99, K9A, K9B, K9C, K9D, K9E, K9F, KA0, KA1, KA2, KA3, KA4, KA5, KA6, KA7, KA8, KA9, KAA, KAB, KAC, KAD, KAE, KAF, KB0, KB1, KB2, KB3, KB4, KB5, KB6, KB7, KB8, KB9, KBA, KBB, KBC, KBD, KBE, KBF, KC0, KC1, KC2, KC3, KC4, KC5, KC6, KC7, KC8, KC9, KCA, KCB, KCC, KCD, KCE, KCF, KD0, KD1, KD2, KD3, KD4, KD5, KD6, KD7, KD8, KD9, KDA, KDB, KDC, KDD, KDE, KDF, KE0, KE1, KE2, KE3, KE4, KE5, KE6, KE7, KE8, KE9, KEA, KEB, KEC, KED, KEE, KEF, KF0, KF1, KF2, KF3, KF4, KF5, KF6, KF7, KF8, KF9, KFA, KFB, KFC, KFD, KFE, KFF}

void	ft_putnbrhexa(size_t nb)
{
	char	c;
	char	ech[16] = "0123456789ABCDEF";

	if (!(nb / 16) && !(nb % 16))
	{
		write(1, "0", 1);
		return ;
	}
	if (nb / 16)
		ft_putnbrhexa(nb / 16);
	c = ech[nb % 16];
	write(1, &c, 1);
}

void	ft_putnbrhexa_ndl(int nb)
{
	ft_putnbrhexa(nb);
	write(1, "\n", 1);
}

int		main(void)
{
	int 	i;
	int		j;
	int 	t;
	char	CHTAB;

	i = 0;
	while (++i < 0x98)
	{
		write(1, chtab[i], 5);
		write(1, "test ", 5);
		if (i < 0x10)
			write(1, "0", 1);
		ft_putnbrhexa_ndl(i);
		write(1, RESET, 4);
		if (i == 0x04)
			i += 2;
		if ((0x07 <= i) && (i < 0x29))
			i = 0x29;
		if (i == 0x36)
			i += 3;
		if ((0x47 <= i) && (i < 0x89))
			i = 0x89;
		if ((i % 16) == 0x09)
			i += 6;
	}

	return 0;
}