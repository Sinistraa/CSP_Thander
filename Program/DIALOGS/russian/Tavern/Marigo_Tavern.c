// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat("Все сплетни города "+ GetCityName(npchar.city) +" к вашим услугам. Что бы вы хотели узнать?",
                          "Мы только что поднимали это тему. Вы, вероятно, запамятовали...", "Сегодня вы уже третий раз говорите о каком-то вопросе...",
                          "Что ты "+ GetSexPhrase("заладил","заладила") +" как попугай одно и то же...", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Знаешь, " + NPChar.name + ", как-нибудь в следующий раз.", "Точно, "+ GetSexPhrase("забыл","забыла") +" что-то...",
                      "Да уж, действительно в третий раз...", "Да уж...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";

			//виспер
			if(CheckAttribute(pchar, "Whisper.FindDesouzaHol"))
			{
				DeleteAttribute(pchar, "Whisper.FindDesouzaHol")
				link.l1 = "Послушай, к тебе тут случаем не подходили ребята подозрительной наружности? У них ещё должно быть клеймо в форме распятия на руке.";
				link.l1.go = "FindDesouzaHol";
				break;
			}
			//виспер
			
			// ==> Анжелика Тич: Портниха знатной дамы
			if(CheckAttribute(pchar, "questTemp.AT_PZD_taverna"))
			{
				DeleteAttribute(pchar, "questTemp.AT_PZD_taverna")
				link.l1 = "Среди твоих постояльцев есть испанцы. Не знаешь, откуда они, или на каком корабле приплыли?";
				link.l1.go = "AT_PZD_taverna_1";
				break;
			}
			// <== Анжелика Тич: Портниха знатной дамы

			// ==> Проверяем поле состояния квестов.
			switch(pchar.questTemp.State)
            {
                case "SeekChumakeiro_ToAaronHouse": //Голландская линейка, квест №1. поиски Чумакейро.
                    link.l1 = HeroStringReactionRepeat("Послушай, у вас в Мариго гостит некий Аарон Мендес Чумакейро. Знаешь такого?",
                    "Я про Аарона "+ GetSexPhrase("хотел","хотела") +" спросить... уже выяснили, извини.", "Аарон, Аа-а-аро-о-он...", "С Аароном разобрались, извини...", npchar, Dialog.CurrentNode);
                    link.l1.go = DialogGoNodeRepeat("Step_H1_1", "", "", "", npchar, Dialog.CurrentNode);
                break;

            }
            // <== Проверяем поле состояния квестов.


 		break;
		//============ Анжелика Тич: Портниха знатной дамы
		case "AT_PZD_taverna_1":
    		dialog.text = "Мне сейчас не до болтовни с посетителями. Испанцы, португальцы, сам морской дьявол разве что сегодня ещё не заглядывал.";
    		link.l1 = "Значит дела идут?";
    		link.l1.go = "AT_PZD_taverna_2";
 		break;
		case "AT_PZD_taverna_2":
    		dialog.text = "Грех жаловаться. У нас тут, что ни вечер, губернатор устраивает в резиденции приёмы в честь исполнившегося совершеннолетия своих дочерей. То посол какой прибудет, то ещё кого принесёт и все на чём-то приплывают. Матросов набивается, только успевай подносы подавать. Ты лучше в портовое управление загляни, любой капитан там отмечается. А-а! Да что тебе-то рассказывать.";
			link.l1 = "Да, пожалуй, так и сделаю.";
    		link.l1.go = "exit";
 		break;
        //============ Голландская линейка, квест №1. поиски Чумакейро.
 		case "Step_H1_1":
    		dialog.text = "Знаю. Я ему подыскал подходящий дом для съёма. Хороший человек, заплатил прилично...";
    		link.l1 = "Понятно... А где этот дом, который снял Аарон?";
    		link.l1.go = "Step_H1_2";
 		break;
 		case "Step_H1_2":
    		dialog.text = "Между борделем и резиденцией ГВИК. Небольшой кирпичный дом, слегка обветшавший снаружи. Но внутри там всё в порядке, " + npchar.name + " худого людям не делает.";
    		link.l1 = "Спасибо тебе, пойду навещу этого Аарона.";
    		link.l1.go = "Step_H1_3";
 		break;
 		case "Step_H1_3":
    		dialog.text = "Занимай очередь.";
    		link.l1 = "Как понять?";
    		link.l1.go = "Step_H1_4";
 		break;
 		case "Step_H1_4":
    		dialog.text = "Так и понять - занимай очередь навестить Аарона. О нем уже спрашивали и, видимо, отправились к нему на встречу.";
    		link.l1 = "Кто?";
    		link.l1.go = "Step_H1_5";
 		break;
 		case "Step_H1_5":
    		dialog.text = "Какой-то незнакомец, первый раз его видел у нас в городе. У Аарона сегодня день открытых дверей, хе-хе.";
    		link.l1 = "М-да, похоже на то... Ну да ладно, спасибо тебе ещё раз. Прощай.";
    		link.l1.go = "exit";
 		break;
		case "FindDesouzaHol":
    		dialog.text = "Ко мне нет, но к моей официантке приставали типы, подходящие под описание. Можешь у неё узнать подробности.";
    		link.l1 = "Хорошо, спасибо.";
			pchar.Whisper.FindDesouzaHolWaitress = true;
    		link.l1.go = "exit";
 		break;


	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}

