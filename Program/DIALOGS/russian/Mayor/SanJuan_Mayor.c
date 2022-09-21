// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Что вы хотели? Спрашивайте.", "Я слушаю вас, что за вопрос?"), "Второй раз за день вы пытаетесь задать ворпос...", "В третий раз за день вы опять пытаетесь задать вопрос...",
                          "Да когда же это кончится?! У меня дел полно по управлению делами города, а ты все вопросы пытаешься задать!", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Я передумал"+ GetSexPhrase("","а") +"...", "Не сейчас, не место и не время..."), "Да, верно... Но не сейчас, позже...",
                      "Задам, задам... Только позже...", "Извините, " + GetAddress_FormToNPC(NPChar) + "...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			if (CheckAttribute(pchar, "RomanticQuest.MayorOk"))
			{
				link.l1 = "Сеньор губернаор, я капитан " + GetFullName(pchar) + ". Это я венчался в церкви города с вдовой Изабеллой Олеварес, урожденной де Вальдес.";
				link.l1.go = "Romantic_1";
			}
		break;
		case "Romantic_1":
			dialog.text = "Вы как нельзя вовремя, капитан! Я уже посылал за вами коменданта.\n"+
				          "Ну, а раз уж вы здесь, расскажите мне, ради всего святого, что за ужасную резню вы устроили в нашей церкви!";
			link.l1 = "Сеньор " + npchar.lastname + ", я попросту защищал свою жизнь, честь и Изабеллу, мою жену...";
			link.l1.go = "Romantic_2";
		break;
		case "Romantic_2":
			dialog.text = "Звучит прекрасно, капитан. Но только я жду подробностей того, что взбудоражило весь город!";
			link.l1 = "Сеньор губернатор, покойный муж Изабеллы - Сальватор Олеварес - был изрядным мерзавцем. За ним тянется целый шлейф мерзких преступлений, среди которых немало убийств...";
			link.l1.go = "Romantic_3";
		break;
		case "Romantic_3":
			dialog.text = "Это мне известно. По приезду из Белиза от своей кузины Фернандес, Изабелла была у меня на приеме и рассказала обо всем этом. Так вы и есть ее спаситель?";
			link.l1 = "Да, сеньор губернатор. Полагаю, ничего удивительного нет в том, что мы с Изабеллой решили обвенчаться сразу же, как только это стало возможным. Однако мерзавец Сальватор, еще до того как погибнуть, нанял целую шайку омерзительного отребья со всего Карибского моря для того, чтобы уничтожить нас.";
			link.l1.go = "Romantic_4";
		break;
		case "Romantic_4":
			dialog.text = "И в церкви были те самые наемники?";
			link.l1 = "Именно так, сеньор губернатор. Полагаю, я сделал много полезного для всего региона, уничтожив сразу столько бандитов...";
			link.l1.go = "Romantic_5";
		break;
		case "Romantic_5":
			dialog.text = "Бесспорно, капитан, так оно и есть. Ну что же, теперь мне все достаточно ясно. Полагаю, мы проведем обряд освещения церкви за общественный счет.";
			link.l1 = "Сеньор губернатор, огромное вам спасибо за понимание ситуации...";
			link.l1.go = "Romantic_6";
		break;
		case "Romantic_6":
			dialog.text = "Разбираться в таких делах - мой долг, капитан! Ну, что же, я желаю вам счастья со своей супругой. Примите поздравления.";
			link.l1 = "Спасибо, сеньор губернатор!";
			link.l1.go = "exit";
			AddQuestRecord("Romantic_Line", "27");
			DeleteAttribute(pchar, "RomanticQuest.MayorOk");
			LocatorReloadEnterDisable("SanJuan_town", "houseSp6", false); //и только теперь открываем дверь в дом Изабеллы
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}

