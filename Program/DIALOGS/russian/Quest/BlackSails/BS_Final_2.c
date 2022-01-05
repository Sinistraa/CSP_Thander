
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog, "Links");

	makeref(NPChar, CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	switch (Dialog.CurrentNode)
	{
	case "Exit":
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
		break;

		/*
		==Начало в части 3== BS_F3_1 - BS_F3_22
//Скипаем с отравления три дня. ГГ приходит в себя в комнате таверны.
//Запись в СЖ: «Неожиданно. Но предсказуемо. Флинт поимел нас всех. Кто бы мог подумать. Хорошо, что жив(ва) остался(лась)! Нужно разобраться в происходящем. Дьявол, как же мутит то!»
		case "BS_F2_1":	//Максин
			dialog.text = "Очнул"+ GetSexPhrase("ся","ась") +" наконец, ты дольше всех в отключке был"+ GetSexPhrase("","а") +"";
			link.l1 = "Все живы? Что нового?";
			link.l1.go = "BS_F2_2";
CloseQuestHeader("BSUrka");
SetQuestHeader("BSSevereHangover");
AddQuestRecord("BSSevereHangover", "1");
AddQuestUserData("BSSevereHangover", "sSex", GetSexPhrase("","а"));
		break;
		==Начало в части 3== BS_F3_1 - BS_F3_22
*/

		//ВАРИАНТ 2 - помощь Бонсу, а позже Вейну.
		//Если ищем Вейна, то при визите в Ла Вегу – он в Пуэрто-Присипе, если на Кубу, то в Ла Веге.
		//Прибыв в один из вариантов – запись в СЖ: «’Рейнджера’ на рейде не видно. Расспрошу местных»		 	AddQuestRecord("BSSevereHangover", "41");
	case "BS_F2_23": //Бармены и мэры Ла Веги/ПуэртоПринсипе
		dialog.text = "Нет, капитан Вейн тут давно не появлялся";
		link.l1 = "...";
		link.l1.go = "exit";
		break;

		//Плывём на второй вариант.
		//Запись в СЖ: «’Рейнджер’ на якоре! Шлюпку на воду!»		AddQuestRecord("BSSevereHangover", "42");
	case "BS_F2_24": //Говорим с вахтенным
		dialog.text = "";
		link.l1 = "Привет, " + GetFullName(NPChar) + ", где капитан? Разговор к нему есть.";
		link.l1.go = "BS_F2_25";
		break;
	case "BS_F2_25":
		dialog.text = "Высадился вчера с абордажной ротой и в джунгли ушел. В посёлке шума навёл, чуть до драки дело не дошло, наши опасаются на берег сходить";
		link.l1 = "Дипломатия Вейна. Ха. Понимаю. Я на берег, не упейтесь тут с моими!";
		link.l1.go = "exit";
		break;

		//Высаживаемся на берег, идём в поселение. У главы или бармена диалог
	case "BS_F2_26": //Бармены и мэры Ла Веги/ПуэртоПринсипе
		dialog.text = "";
		link.l1 = "Я слышал" + GetSexPhrase("", "а") + " капитан Вейн у вас тут отметился на днях. Чего буянил-то?";
		link.l1.go = "BS_F2_27";
		break;
	case "BS_F2_27":
		dialog.text = "Пират он уважаемый и лихой, вот только горячий слишком. Имущество тут попортил, пару голов разбил и был таков";
		link.l1 = "И куда направился? У нас с ним общее дело и я, конечно не столь уважаемый пират, но имущество и головы портить тоже умею!";
		link.l1.go = "BS_F2_28";
		break;
	case "BS_F2_28":
		dialog.text = "Далеко, в джунгли. Там лагеря рабов беглых со всего архипелага";
		link.l1 = "А Флинт тут не объявлялся?";
		link.l1.go = "BS_F2_29";
		break;
	case "BS_F2_29":
		dialog.text = "Давно не было, раньше часто ходил в джунгли";
		link.l1 = "Проводники есть, которые лагеря укажут?";
		link.l1.go = "BS_F2_30";
		break;
	case "BS_F2_30":
		dialog.text = "Был один, с Вейном ушел";
		//Запись в СЖ: «Возможность последовать за Вейном я упустил(), без опытных проводников, соваться в джунгли – самоубийство. Что же, подожду тут»
		AddQuestRecord("BSSevereHangover", "43");
		link.l1 = "Черт. Остаётся только ждать. Бывай";
		link.l1.go = "exit";
		break;

		//Снимаем комнату, на второй день в таверну приходят Вейн и чел с моделькой негра, в красной рубахе Коффи.
	case "BS_F2_29": //Вейн
		dialog.text = "";
		link.l1 = "Привет Чарльз. Еле наш" + GetSexPhrase("ёл", "ла") + " тебя! Кто это с тобой?"; //Qwerry: Друг? Толерастия!
		link.l1.go = "BS_F2_30";
		break;
	case "BS_F2_30": //Вейн
		dialog.text = "Это Коффи, кто-то вроде вождя у беглых. И он знает, где Флинт.";
		link.l1 = "";
		link.l1.go = "BS_F2_30_1";
		break;
	case "BS_F2_30_1":
		DialogExit();
		sld = CharacterFromID(""); //TO DO<<<<<<<<!!!!!!!указать имя===================================<<<<<<<<<<<<<<<<<<<<<<<<
		sld.dialog.filename = "Quest\BlackSails\BS_Final_2.c";
		sld.dialog.currentnode = "BS_F2_31";
		pchar.InstantDialog = sld.id;
		DoQuestFunctionDelay("InstantDialog", 0);
		break;
	case "BS_F2_31": //Коффи
		dialog.text = "Коффи знает. Вейн обещал помочь. Коффи говорит, где Флинт.";
		link.l1 = "";
		link.l1.go = "BS_F2_31_1";
		break;
	case "BS_F2_31_1":
		DialogExit();
		sld = CharacterFromID("BS_Vein");
		sld.dialog.filename = "Quest\BlackSails\BS_Final_2.c";
		sld.dialog.currentnode = "BS_F2_32";
		pchar.InstantDialog = sld.id;
		DoQuestFunctionDelay("InstantDialog", 0);
		break;
	case "BS_F2_32": //Вейн
		dialog.text = "Кремень парень, ничто его не пронимает. Суть такова: Флинт обещал переправить беглых на материк, в северные колонии. Там никому дела нет, кто ты и откуда. Да только обещание сдержал частично. Тех,  что на корабль попали – вербуют, а тех,  кто против – сразу за борт. Затевает Флинт что-то вроде войны с колониальными властями. Сам в короли метит. А добыча наша – это казна его королевства";
		link.l1 = "Флинт - амбициозный человек! Не могу не уважать его.";
		link.l1.go = "BS_F2_33";
		break;
	case "BS_F2_33": //Вейн
		dialog.text = "Да хоть в засос целуйся с ним! Сначала наши деньги, потом голова Флинта, после чего делай с ней что хочешь!";
		link.l1 = "";
		link.l1.go = "BS_F2_33_1";
		break;
	case "BS_F2_33_1":
		DialogExit();
		sld = CharacterFromID(""); //TO DO<<<<<<<<!!!!!!!указать имя===================================<<<<<<<<<<<<<<<<<<<<<<<<
		sld.dialog.filename = "Quest\BlackSails\BS_Final_2.c";
		sld.dialog.currentnode = "BS_F2_34";
		pchar.InstantDialog = sld.id;
		DoQuestFunctionDelay("InstantDialog", 0);
		break;
	case "BS_F2_34": //Коффи
		dialog.text = "Вейн обещал помочь!";
		link.l1 = "";
		link.l1.go = "BS_F2_34_1";
		break;
	case "BS_F2_34_1":
		DialogExit();
		sld = CharacterFromID("BS_Vein");
		sld.dialog.filename = "Quest\BlackSails\BS_Final_2.c";
		sld.dialog.currentnode = "BS_F2_35";
		pchar.InstantDialog = sld.id;
		DoQuestFunctionDelay("InstantDialog", 0);
		break;
	case "BS_F2_35": //Вейн
		dialog.text = "Губернатор местный недавно решил оружием побряцать перед какой-то шишкой из метрополии. Солдаты отловили кучку беглых по джунглям и продали их на плантацию. На Барбадос. Наш друг просит освободить его подданных, а взамен сдаст укрытие Флинта.";
		link.l1 = "Плантация на Барбадосе – это каторга британской короны, в ущелье, прикрытая пушками форта и городскими стенами. После набега испанцев там гарнизон, усиленный из морской пехоты и наёмников шведов. Это, мать её, крепость"; //Qwerry: Нужна особая реплика для Блада?
		link.l1.go = "BS_F2_36";
		break;
	case "BS_F2_36":
		dialog.text = "Значит возьмём её штурмом!";
		link.l1 = "На такое чтобы пойти – это подготовка нужна... и эскадра... и народу под тысячу или больше, а времени в обрез. Двигаем к Барбадосу, есть идея как малой кровью провернуть это дело. Становись в эскадру.";
		link.l1.go = "exit";
		AddQuestRecord("BSSevereHangover", "44");
		//Запись в СЖ: «Флинт строит своё королевство. Вот так новость. Не удивлюсь, если он принц крови, в изгнании или бастард королевский. Информация о его схроне стоит дорого. Но надеюсь дело того стоит. Направляемся на Барбадос. Нужно продумать атаку плантации»
		break;

		//Высаживаемся на мысе Гаррисон. На берегу Вейн, куча матросни.
	case "BS_F2_37": //Вейн
		dialog.text = "";
		link.l1 = "Я отправил" + GetSexPhrase("", "а") + " разведчиков узнать, как тут и что. Как вернуться – проведут вас к плантации, слышал" + GetSexPhrase("", "а") + " я слухи, что там тропки в горах есть. А я в город мотнусь, разнюхаю обстановку. Мои парни переоденутся поприличнее и через ворота городские поближе к плантации подойдут. Как будет всё готово, ударим с двух сторон одновременно. Сигнал – мушкетный залп.";
		link.l1.go = "BS_F2_38";
		break;
	case "BS_F2_38": //Вейн
		dialog.text = "А вы с Флинтом похожи. Думаете одинаково. Той же дорожкой пойдёшь?";
		link.l1 = "Тебя это беспокоит? У нас есть дело и его нужно провернуть без ошибок. Всё, я в город, жди возвращения разведчиков и выдвигайтесь.";
		link.l1.go = "exit";
		//Запись в СЖ: «Я на Флинта похожу? Что за бред. Осмотрюсь в городе, пока мои бойцы проникают за ворота».
		AddQuestRecord("BSSevereHangover", "45");
		break;

		//Проникаем в город. Просто бродим туда-сюда. У выхода из борделя встречаем Сильвера.
	case "BS_F2_39": //Сильвер
		dialog.text = "";
		link.l1 = "Вот так сюрприз! Джон, давно не виделись! Флинт тоже тут?";
		link.l1.go = "BS_F2_40";
		break;
	case "BS_F2_40": //Сильвер
		dialog.text = "Удрал я от Флинта, он от старой команды избавляться начал, прям в море. Вся палуба кровью пропиталась. Еле ноги унёс! Ищу, вот, кто бы до материка подкинул, исчезнуть мне нужно";
		link.l1 = "С чего бы Флинт от тебя избавиться захотел?";
		link.l1.go = "BS_F2_41";
		break;
	case "BS_F2_41": //Сильвер
		dialog.text = "Концы в воду! Своей цели он добился, золото получил, теперь за следующую принялся.";
		link.l1 = "Ты про королевство свободных пиратов? Наслышан" + GetSexPhrase("", "а") + ".";
		link.l1.go = "BS_F2_42";
		break;
	case "BS_F2_42": //Сильвер
		dialog.text = "Слушай, мы не ссорились и крови между нами нету. Давай разбежимся?";
		link.l1 = "Нутром чую, что ты что-то недоговариваешь, но времени нет разбираться. Ладно, исчезни.";
		link.l1.go = "exit";
		AddQuestRecord("BSSevereHangover", "46");
		//Запись в СЖ: «На улицах Бриджтауна встретил() Джона Сильвера, говорит, что сбежал от Флинта. Подозрительный тип, глазки бегают и напуган явно не мной. Ладно, к дьяволу Сильвера. Пора выдвигаться к плантации».
		break;
		//Сильвер уходит

		//Плантация. Кучка англичан – солдат у входа. Человек 15 наших. Четверо с мушкетами.
	case "BS_F2_43": //ГГ сам себе
		dialog.text = "";
		link.l1 = "Огонь по мундирам! Залпом, пли!";
		link.l1.go = "exit";
		break;

		//Бабах!! Начинается файт. Англичане прут в три волны со стороны плантации. На третьей волне со стороны плантации – Вейн с бригадой. Мясо. Говорим ч Вейном
	case "BS_F2_44": //Вейн
		dialog.text = "";
		link.l1 = "Ты опоздал! Нас чуть не покрошили!";
		link.l1.go = "BS_F2_45";
		break;
	case "BS_F2_45": //Вейн
		dialog.text = "Патрули в горах, ползли на брюхе, чтоб раньше времени шум не поднять!";
		link.l1 = "Ладно, дело сделано, соберите каторжан в кучу, пусть подберут себе оружие и отступаем в горы. Слышишь? Дьявол, гарнизон из города идёт. К бою!";
		link.l1.go = "exit";
		break;

		//Со стороны города прут ещё пару волн англичан. Файт
	case "BS_F2_46": //Qwerry: Вейн? или сразу после боя сам себе?
		dialog.text = "";
		link.l1 = "Отбились, скоро и из форта подойдут мундиры! Бегом в горы!";
		link.l1.go = "exit";
		break;
		//Загрузка. Перемещаем ГГ, Вейна, матросов и кучку каторжан на пляж мыса Гаррисон.
	case "BS_F2_47": //Вейн
		dialog.text = "Дело за малым. Выгружаем бедолаг в Ла Веге. Коффи там ждать будет.";
		link.l1 = "На всех парусах! Не хватало ещё со сторожевиками воевать.";
		link.l1.go = "exit";
		break;

		//Выходим в море. На глобалке атакует фиолетовая энка. «Скарборо» линейник 1 ранга и с ним пара фрегатов. Морской бой.
		//Если брать на абордаж «Скарборо» - капитан Френсис Ньюм, моделька офицера английского. Файт в каюте. Диалог
	case "BS_F2_48": //Ньюм
		dialog.text = "Именем короля! Сдавайтесь!";
		link.l1 = "«Ха. Вас взяли на абордаж, капитан. Сами сдавайтесь! И какого черта вы атаковали нас? У нас же договор с коммандером Блэкхемом!";
		link.l1.go = "BS_F2_49";
		break;
	case "BS_F2_49": //Ньюм
		dialog.text = "Блэкхем разжалован и арестован за сотрудничество с пиратами, его ждёт суд и виселица в Бостоне.";
		link.l1 = "Так я и знал" + GetSexPhrase("", "а") + ", что все слова о помиловании и наградах – дерьмо собачье! Время умирать!";
		link.l1.go = "exit";
		AddQuestRecord("BSSevereHangover", "47");
		//Запись в СЖ: «Каторжники отбиты. Недалеко от Барбадоса, были атакованы «Скарборо», капитан Ньюм, перед смертью рассказал о судьбе Билли. Туда и дорога. Путь на Эспаньолу, в Ла Вега ждёт своих соплеменников Кофии».
		break;

		//Берег Ла Веги. Вейн, ГГ, Коффи.
	case "BS_F2_50": //Коффи
		dialog.text = "";
		link.l1 = "Вот твои друзья Коффи, мы свою часть сделки выполнили. Где Флинт?";
		link.l1.go = "BS_F2_51";
		break;
	case "BS_F2_51": //Коффи
		dialog.text = "В двух днях пути отсюда есть заброшенный дом. Там жила женщина Флинта. Он часто ходить туда. Коффи покажет дорога.";
		link.l1 = "Я готов" + GetSexPhrase("", "а") + " идти хоть сейчас. Вейн?";
		link.l1.go = "BS_F2_51_1";
		break;
	case "BS_F2_51_1":
		DialogExit();
		sld = CharacterFromID("BS_Vein");
		sld.dialog.filename = "Quest\BlackSails\BS_Final_2.c";
		sld.dialog.currentnode = "BS_F2_52";
		pchar.InstantDialog = sld.id;
		DoQuestFunctionDelay("InstantDialog", 0);
		break;
	case "BS_F2_52": //Вейн
		dialog.text = "Я тоже";
		link.l1 = "";
		link.l1.go = "BS_F2_52_1";
		break;
	case "BS_F2_52_1":
		DialogExit();
		sld = CharacterFromID(""); //TO DO<<<<<<<<!!!!!!!указать имя===================================<<<<<<<<<<<<<<<<<<<<<<<<
		sld.dialog.filename = "Quest\BlackSails\BS_Final_2.c";
		sld.dialog.currentnode = "BS_F2_53";
		pchar.InstantDialog = sld.id;
		DoQuestFunctionDelay("InstantDialog", 0);
		break;
	case "BS_F2_53": //Коффи
		dialog.text = "";
		link.l1 = "Вы идти след в след. Коффи покажет как.";
		link.l1.go = "BS_F2_54";
		break;

		//Загрузка, дом в джунглях. Коффи остаётся у выхода из локи. ГГ с Вейном заходят в дом. В сундуке 2кк денег, книга Марк Аврелий «Размышления».
	case "BS_F2_54": //Вейн
		dialog.text = "Зола ещё горячая. Он был тут недавно. Устроим засаду?";
		link.l1 = "В сундуке деньги и старая книга. Свою долю сейчас возьмёшь?"; //Qwerry: Реплика до обыска сундука или после должна быть? Нужен ли вообще обыск сундука?
		link.l1.go = "BS_F2_55";
		break;
	case "BS_F2_55": //Вейн
		dialog.text = "Позже. Сначала прищучим Флинта.";
		link.l1 = "Как скажешь. Давай осмотримся снаружи.";
		link.l1.go = "exit";
		break;

		//Выходим. На улице труп Коффи, Флинт.
	case "BS_F2_56": //Флинт
		dialog.text = "Всего не предусмотришь. Не так ли? А вы мне нравились. Зачем погнались за мной? Золота ‘Урки’ вам всё равно не видать. Оно надёжно спрятано.";
		link.l1 = "";
		link.l1.go = "BS_F2_56_1";
		break;
	case "BS_F2_56_1":
		DialogExit();
		sld = CharacterFromID("BS_Vein");
		sld.dialog.filename = "Quest\BlackSails\BS_Final_2.c";
		sld.dialog.currentnode = "BS_F2_57";
		pchar.InstantDialog = sld.id;
		DoQuestFunctionDelay("InstantDialog", 0);
		break;
	case "BS_F2_57": //Вейн
		dialog.text = "Значит найдём, но сначала поквитаюсь с тобой!";
		link.l1 = "";
		link.l1.go = "BS_F2_58";
		break;
		//Вейн кидается в атаку – Флинт скриптово стреляет в него. Вейн падает. И атакует ГГ
		//Сурьёзный замес. Нулим НР Флинту – он скриптово стреляет, нас корчит, Флинт убегает.

	case "BS_F2_58": //ГГ себе
		dialog.text = "Черт, ребро сломано! Вейн, ты как, дружище? Рана серьёзная, он может истечь кровью";
		link.l1 = "Остаться и перевязать Вейна.";
		link.l1.go = "BS_F2_59";
		break;

		//Прошло четыре дня. Еле-еле с раненым Вейном доковыляли до кораблей.  Загрузкой с табличкой, повествующей о событиях.
		//Запись в СЖ: «Логово Флинта найдено и сам Флинт тоже. Внушительная сумма денег и старая книга. Мерзавец скрылся. Понятия не имею, что делать дальше. Доставлю Чарльза на Бермуды и обмозгуем с Гатри варианты».
		//			AddQuestRecord("BSSevereHangover", "48");

		//Отплываем на Бермуды, выводим «Рейнджера» из эскадры.
		//Бермуды. Резиденция закрыта. Идём в таверну.
	case "BS_F2_59": //бармен
		dialog.text = "";
		link.l1 = "Слушай, а где мисс Гатри? Резиденция закрыта...";
		link.l1.go = "BS_F2_60";
		break;
	case "BS_F2_60": //бармен
		dialog.text = "Тут недавно английские военные высадились. Человек пятьсот и в бухте линейник «Скарборо» встал. Устроили тут, черт знает что. Мисс Гатри и ещё несколько человек арестовали. Капитан Ньюм орал, что их настигло правосудие, и суд в Порт Рояле будет скорым.";
		link.l1 = "Как? Мне нужно спешить. Прощай.";
		link.l1.go = "BS_F2_61";
		AddQuestRecord("BSSevereHangover", "49");
		//Запись в СЖ: «Гатри арестована Ньюмом! Тем самым, кого я на корм рыбам отправил(ла)! Поспешу в Порт Рояль, может быть Максин чем то поможет. И не слова Вейну, какие у них бы там отношения не были, наделает глупостей. Слишком горяч. В порт заходить не стоит, неизвестно чем всё там обернётся»
		break;

		//Высаживаемся в бухте, топаем в город. Сразу в бордель.
	case "BS_F2_61": //Максин
		dialog.text = "Я знаю, зачем ты здесь. Недавно капитан Ньюм устроил в городе целое представление. Провёл из порта в форт Элеонору и Бонса, в цепях. Герой, победитель пиратов. Напыщенный индюк.";
		link.l1 = "Дохлый индюк! Я встретил" + GetSexPhrase("", "а") + " ‘Скарборо’ у Барбадоса и пустил" + GetSexPhrase("", "а") + " на дно! Пленники всё ещё тут?";
		link.l1.go = "BS_F2_62";
		break;
	case "BS_F2_62":
		dialog.text = "Да, в форте. Что ты задумал" + GetSexPhrase("", "а") + "? Это самоубийство! Им не помочь уже!";
		link.l1 = "Им? Мне плевать на Бонса, он вполне заслуживает виселицы. Я хочу вытащить Элеонору и смыться отсюда на всех парусах! Ты со мной? Корабль стоит в бухте Портленд.";
		link.l1.go = "BS_F2_63";
		break;
	case "BS_F2_63":
		dialog.text = "Нет, прости. Я долго добивалась того, что сейчас имею. Хватит с меня авантюр!";
		link.l1 = "Мы нашли схрон Флинта, но мерзавец удрал, сильно ранив Вейна при этом. Тут часть денег. Уверен" + GetSexPhrase("", "а") + " – это золото ’Урки’. Держи, твоя доля - 500 тысяч.";
		link.l1.go = "BS_F2_64";
		break;
	case "BS_F2_64":
		AddmoneyToCharacter(PChar, -500000);
		dialog.text = "Может хватит гоняться за остальным? Довольствуйся тем, что судьба посылает!";
		link.l1 = "Я не остановлюсь в конце пути!";
		link.l1.go = "BS_F2_65";
		break;
	case "BS_F2_65":
		dialog.text = "Иногда нужно! Ты погубишь себя!";
		link.l1 = "Спасибо за заботу, но я сам" + GetSexPhrase("", "а") + " управляю своей судьбой. Прощай Макс. Может, ещё увидимся!";
		link.l1.go = "exit";
		break;

		//Топаем в форт. В тюрьму. Комендант пропускает без вопросов. В камере – Бонс
	case "BS_F2_66":
		dialog.text = ""; //Бонс
		link.l1 = "Сэр Уильям! Какая встреча! Решили сменить роскошную каюту на апартаменты попроще?";
		link.l1.go = "BS_F2_67";
		break;
	case "BS_F2_67":
		dialog.text = "Что-то новое. А то всем подавай клады пиратские или просто кинуть гнилью. Какими судьбами, капитан?";
		link.l1 = "Где мисс Гатри?";
		link.l1.go = "BS_F2_68";
		break;
	case "BS_F2_68":
		dialog.text = "Ах, да. Королева пиратов. Вы опоздали, вчера на рассвете её отправили в Англию курьерским бригом. Хотят повесить в самом Лондоне.";
		link.l1 = "...";
		link.l1.go = "BS_F2_69";
		break;
	case "BS_F2_69":
		dialog.text = "Нет слов? Понимаю, иногда всё летит к чертям. И ты просто не понимаешь, что происходит.";
		link.l1 = "Как ты тут очутился? В прошлый раз ты выглядел бравым имперским рыцарем!";
		link.l1.go = "BS_F2_70";
		break;
	case "BS_F2_70":
		dialog.text = "Флинт тому виной. Не дождавшись новостей от тебя, я предпринял поиски самостоятельно. И нарыл кое-что. Места стоянок ‘Моржа’. Он ещё более неуловим, чем Урка. Вот только, я был самонадеян и отправился на поиски один. И в определённом месте нарвался на Флинта и ещё два фрегата. Явно не местные. Бой был жарким, потом абордаж. Сумел даже пробиться в каюту Флинта. В горячке боя так увлёкся, что единолично пробился туда, а там засада. Как выжил – сам не знаю. Очнулся на берегу.";
		link.l1 = "А потом тебя подобрал ‘Скарборо’.";
		link.l1.go = "BS_F2_71";
		break;
	case "BS_F2_71":
		dialog.text = "Точно. Ньюм был очень доволен собой и решил повесить на меня все свои неудачи. Напыщенный самодовольный кретин! Слушай, сделаешь одолжение? Прикончи его при встрече.";
		link.l1 = "Уже. Что мне с тобой делать, Билли? Говоришь, тебе известны места стоянок Флинта? Поделишься?";
		link.l1.go = "BS_F2_72";
		break;
	case "BS_F2_72":
		dialog.text = "С чего бы это?";
		link.l1 = "Я Ньюма убил" + GetSexPhrase("", "а") + ".";
		link.l1.go = "BS_F2_73";
		break;
	case "BS_F2_73":
		dialog.text = "Его бы и собственный адъютант прирезал во время бритья. Слушай, вытащи меня отсюда? Сдам тебе Флинта.";
		link.l1 = "Поверить тебе - это явно ошибка. Но у меня просто нет никаких идей, что делать дальше. Ладно. Отойди.";
		link.l1.go = "exit";
		break;
		//Скриптово стреляем в замок, Бонс в абордаги, месим стражу, удираем в бухту. Пиздим на берегу с Бонсом.

	case "BS_F2_74": //Бонс
		dialog.text = "";
		link.l1 = "Флинт.";
		link.l1.go = "BS_F2_75";
		break;
	case "BS_F2_75":
		dialog.text = "Лагуна Чирики, бухта Бока де ла Сьертэ. Я имел удовольствие с ним встретиться у мыса Каточе, так что его можно вычеркивать.";
		link.l1 = "Отправляйся на корабль, посидишь в трюме. Потом решу, что с тобой делать!";
		link.l1.go = "BS_F2_76";
		break;
	case "BS_F2_76":
		dialog.text = "Так точно, Кэп. Ты прям вылитый Флинт, ещё бы взгляд потренировать!";
		link.l1 = "В шлюпку!";
		link.l1.go = "exit";
		AddQuestRecord("BSSevereHangover", "50");
		AddQuestUserData("BSSevereHangover", "sSex", GetSexPhrase("", "а"));
		//Запись в СЖ: «Неужели я становлюсь Флинтом? Может плюнуть на всё, по совету Макс и довольствоваться малым? Как я устал(ла)! Нужно проверить стоянки, указанные Бонсом»

		//Вешаем НЗГ от Англии.

		break;

		//В Чирике – пусто. Бока де ла Сьрпе – Морж, два фрегата. Месиво, берём Моржа на абордаж – в каюте кэп ОЗГ (наёмник) без диалогов валим пидора. В сундуке СЖ Флинта, зашифрованный, 1кк денег.
		//После абордажа запись в СЖ: «Стоянка найдена, эскадра уничтожена. Флинта на борту Моржа – нет. Высаживаюсь в бухте, нужно проверить здесь всё. В судовом журнале,  какая – то околесица, явно шифр».
		//			AddQuestRecord("BSSevereHangover", "51");
		//На берегу файт в следующей локе – файт.
		//Запись в СЖ: «Флинт как сквозь землю провалился. Перебили уйму наёмников. Что дальше? Клад зарыт где то тут? Что делать?»
		//			AddQuestRecord("BSSevereHangover", "52");

		//Выходим в бухту, на берегу Бонс
	case "BS_F2_77": //Бонс
		dialog.text = "";
		link.l1 = "Нужны твои навыки. В шифровках разбираешься?";
		link.l1.go = "BS_F2_78";
		break;
	case "BS_F2_78":
		dialog.text = "Разбираюсь, по службе часто использовал разные шифры";
		link.l1 = "Вот судовой журнал Флинта, вот зачитанная до дыр книга. (передаём предметы) Перебирайся на кубрик и принимайся за расшифровку. Как прибудем на Бермуды – мне нужны будут готовые ответы.";
		link.l1.go = "exit";
		break;

		//Выходим в море. Идём на Бермуды. Причалив, сразу ТП в резиденцию. Внутри Вейн, Бонс, ГГ
	case "BS_F2_79": //Вейн
		dialog.text = "";
		link.l1 = "Чарльз, смотрю, ты уже на ногах!";
		link.l1.go = "BS_F2_80";
		break;
	case "BS_F2_80":
		dialog.text = "Бывало и хуже. Какие новости?";
		link.l1 = "Элеонору везут в Англию, там будет суд и её, скорее всего, повесят. Флинт испарился, но у нас его судовой журнал и, возможно, мистер Бонс порадует его содержимым. Джек и Бонни – теперь счастливая семья и оставили пиратство, по крайней мере на время, пока Энн не родит маленького Джека, или Джейн. А тут часть денег Флинта. Твоя доля.";
		link.l1.go = "BS_F2_81";
		break;
	case "BS_F2_81":
		AddmoneyToCharacter(PChar, -750000);
		dialog.text = "Черта с два я дам её повесить. Я сам её придушу, когда-нибудь!";
		link.l1 = "Ты твёрдо решил? Мне нужен такой компаньон как ты, Чарльз!";
		link.l1.go = "BS_F2_82";
		break;
	case "BS_F2_82":
		dialog.text = "Твёрже некуда. При другом раскладе, я, может быть и согласился бы. Но ты слишком похож(жа) на Флинта стал(ла)! Передавай привет семейству Рекхэмов. Прощай!";
		link.l1 = "";
		link.l1.go = "BS_F2_83";
		break;
		//Вейн уходит

	case "BS_F2_83": //Бонс
		dialog.text = "Я расшифровал судовой журнал. Взгляни (передаёт несколько страниц, исписанных координатами). Больше ничего.";
		link.l1 = "(пробегает глазами страницы) Оставь себе. Флинт победил. К чертям всё это!";
		link.l1.go = "BS_F2_84";
		break;
	case "BS_F2_84":
		dialog.text = "Стой. Да, тут много координат, чертовски много, но методом исключения... Имея быстрый корабль... Эй, ты слушаешь?";
		link.l1 = "Заткнись, Билли, просто заткнись.";
		link.l1.go = "exit";
		break;
		//Релоад на улицу
		//Запись в СЖ: «Кто такой, этот Флинт? Может сам дьявол? Как я стал(ла) превращаться в него? Бескомпромиссного, жестокого, расчетливого ублюдка! Погоня за его золотом, отобрала часть меня самого(самой). Мудрая шлюха Максин, ты была права. Нужно довольствоваться, тем, что имеешь и не гоняться за чужим, иначе, рискуешь потерять и то, что имеешь»
		//			AddQuestRecord("BSSevereHangover", "53");
		//			AddQuestUserData("BSSevereHangover", "sSex", GetSexPhrase("","а"));
		//			CloseQuestHeader("BSSevereHangover");
		//Квест уходит в архив. Макс остаётся в ПР бригадиром шлюх (бесплатный перепихон). THE END
	}
}
